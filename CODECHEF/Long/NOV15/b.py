import sys

def main():
	sys.version
	t = input()
	print(str(t))
	for i in range(0, t):
		line = raw_input()
		[a, d, l, r] = map(int, line.split())
		
main()
