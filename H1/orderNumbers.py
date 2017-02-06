my_file = open("up.txt", "w")
my_file2 = open("down.txt", "w")

for i in range(1,2049):
	my_file.write(str(i))

	if i != 2048:
		my_file.write(', ')

for i in range(1,2049):
	my_file2.write(str(2049-i))

	if i != 2048:
		my_file2.write(', ')


my_file.close()
my_file2.close()
