import random
import subprocess

stack_size = 100
stack = random.sample(range(-stack_size, stack_size), stack_size)
print(stack)

cmd = "./push_swap " + " ".join(map(str, stack)) + " | ./off_checkers/checker_linux " + " ".join(map(str, stack))
print(cmd)

ps = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
output = ps.communicate()[0]
print(output)
