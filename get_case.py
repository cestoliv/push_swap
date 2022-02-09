import random
import subprocess

exit_max = 700
stack_size = 100

worst = 0

case_found = False
while not case_found:
	stack = random.sample(range(-stack_size, stack_size), stack_size)

	cmd = "./push_swap " + " ".join(map(str, stack)) + " | ./off_checkers/checker_linux " + " ".join(map(str, stack))
	ps = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
	output = ps.communicate()[0]

	if output == b'OK\n':
		cmd = "./push_swap " + " ".join(map(str, stack))
		ps = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
		output = ps.communicate()[0]

		instructions_number = len(str(output).split("\\n")) - 1

		if instructions_number > exit_max:
			case_found = True
			print("Case found (" + str(instructions_number) + " instructions) !")
			print(" ".join(map(str, stack)))
		else :
			if instructions_number > worst:
				worst = instructions_number
				print("worst : " + str(worst), end="\r", flush=True)

	elif output == b'KO\n':
		print("Yo, you doesn't even sort that stack 😂")
