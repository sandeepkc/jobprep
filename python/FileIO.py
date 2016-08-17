#open a file

fo = open('input.txt', 'r')

print ("Name of the file is : " + fo.name)
print ("File is closed or not : ", fo.closed)
print ("Opening mode : " + fo.mode)

file_contents = fo.read()

print (file_contents)

fo.close()