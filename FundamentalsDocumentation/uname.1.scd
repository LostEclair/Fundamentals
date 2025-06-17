uname(1)

# NAME
uname - print system information

# SYNOPSIS
*uname* [-amnrsv]

# DESCRIPTION
The *uname* command writes certain information about the system.
If no options were provided, the *uname* command prints the name of the operating system.

# OPTIONS
*-a*
	Behave as if all of the arguments were provided.

*-m*
	Print the name of the hardware type on which the operating system is running.

*-n*
	Print the name of this node.

*-r*
	Print the current release level of the operating system.

*-s*
	Write the name of the operating system implementation.

*-v*
	Write the current version of the operating system.

# EXIT CODE
The *uname* returns 0 on success.
Other exit codes indicate a failure.
