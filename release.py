# Name: Matthew Bichay
# Course: Systems Development in the Unix Environment
# Semester: Fall 2017
# Description: This script writes TAR files for binary and source releases


import os
import sys
import subprocess
import socket
import getopt


# Confirm Y/N for any question
def confirm(question):
    prompt = ' [Y/N]: '
    choice = raw_input(question+prompt).lower()
    if choice and choice[0] == 'y':
        return True
    return False

# Perform a make it install and capture the bin directory
def generateBinaryRelease(root):
    yes = confirm('You have requested a binary release to be generated.')
    if yes:
        hostName = raw_input('Please enter hostname: ')
        if not hostName:
            hostName = socket.gethostname()

        tarballName = '{}_{}.tar'.format(root, hostName)
        makeCmd = ['make', 'it', 'install']
        tarCmd = ['tar', 'cvf', tarballName, os.path.join(os.curdir, root, 'bin')]
        os.chdir(root)
        subprocess.call(makeCmd)
        os.chdir('..')
        subprocess.call(tarCmd)


# Perform a make clean, then capture the entire root directory
def generateSourceRelease(root):
    yes = confirm('You have requested a source release to be generated.')
    if yes:
        tarballName = '{}.tar'.format(root)
        makeCmd = ['make', 'clean']
        tarCmd = ['tar', 'cvf', tarballName, os.path.join(os.curdir, root)]
        os.chdir(root)
        subprocess.call(makeCmd)
        os.chdir('..')
        subprocess.call(tarCmd)

def main(args):

    root = 'homework1'

    # Parse Arguments from the user -b: binary, -s: source
    try:
        opts, args = getopt.getopt(args, 'bs')
    except getopt.GetoptError as err:
        print(str(err))
        sys.exit(1)

    for opt, arg in opts:
        if opt == '-b':
            generateBinaryRelease(root)
        elif opt == '-s':
            generateSourceRelease(root)


if __name__ == '__main__':
    main(sys.argv[1:])
