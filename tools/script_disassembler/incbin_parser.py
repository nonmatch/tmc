# This python script reads the script.s file which contains all the .incbin macros
# Then it fetches the corresponding data of the baserom, o
TMC_FOLDER='../..'

import subprocess
import sys
from script_disassembler import disassemble_script, generate_macros

ROM_OFFSET=0x08000000
SCRIPTS_START=0x08008B5C
SCRIPTS_END=0x08016984

# Create labels for these additional script instructions
# Currently done by splitting the script at that point
LABEL_BREAKS=[0x0800A088, 0x0800ACE0, 0x0800AD54, 0x0800B41C, 0x0800B7C4, 0x0800C8C8, 0x0800D190, 0x800D3EC, 0x0800E9F4, 0x0800FD80, 0x08012AC8, 0x08012F0C, 0x080130E4, 0x08013B70, 0x080142B0, 0x080147DC, 0x08014A80, 0x08014B10,0x0801635C,  0x08016384, 0x080165D8]

# Generate a version of the script that is annotated with the byte offset to the beginning of the script
GENERATE_REF=False

def read_baserom():
    # read baserom data
    with open(f'{TMC_FOLDER}/baserom.gba', 'rb') as baserom:
        return bytearray(baserom.read())

def get_label(addr):
    return hex(addr).upper().replace('0X', 'gUnk_0')

def main():
    baserom_data = read_baserom()

    script_start = SCRIPTS_START-ROM_OFFSET

    scripts = '''	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.include "asm/macros/scripts.inc"

	.syntax unified

	.text
    
'''

    while script_start < SCRIPTS_END-ROM_OFFSET:
        if len(LABEL_BREAKS) > 0 and script_start+ROM_OFFSET >=LABEL_BREAKS[0]:
            print(f'{hex(script_start+ROM_OFFSET)} > {LABEL_BREAKS[0]}')
            LABEL_BREAKS.pop(0)

        label = get_label(script_start+ROM_OFFSET)
        print(f"Disassembling \033[1;34m{label}\033[0m ({script_start} / { SCRIPTS_END-ROM_OFFSET} bytes converted)...")
        # find end of the script signified by 0xffff0000
        script_end = baserom_data.index(b'\xff\xff\x00\x00', script_start) + 4

        if script_end > SCRIPTS_END-ROM_OFFSET:
            script_end = SCRIPTS_END-ROM_OFFSET

        if len(LABEL_BREAKS) > 0 and script_end+ROM_OFFSET > LABEL_BREAKS[0]:
            print(f'break at {hex(LABEL_BREAKS[0])} instead of {hex(script_end)}')
            script_end = LABEL_BREAKS[0]-ROM_OFFSET

        # read data from rom
        data = baserom_data[script_start:script_end]


        scripts += f'	.include "data/scripts/{label}.inc"\n'
        stdout = sys.stdout

        with open(f'{TMC_FOLDER}/data/scripts/{label}.ref' if GENERATE_REF else f'{TMC_FOLDER}/data/scripts/{label}.inc','w') as out:
            sys.stdout = out
            print(f'SCRIPT_START {label}')
            if GENERATE_REF:
                res = disassemble_script(data, True)
            else:
                res = disassemble_script(data)
            if res != 0:
                # Script ended in the middle, need to create a new file
                script_end = script_start + res
        sys.stdout = stdout

        script_start = script_end 

    if not GENERATE_REF:
        print('Writing scripts.s file...')
        with open(f'{TMC_FOLDER}/data/scripts.s', 'w') as out:
            out.write(scripts)
        print('Generating asm macros...')
        stdout = sys.stdout
        with open(f'{TMC_FOLDER}/asm/macros/scripts.inc', 'w') as out:
            sys.stdout = out
            generate_macros()
        sys.stdout = stdout
    print('\033[1;92mDone\033[0m\n')

if __name__ == '__main__':
    main()