def test_func():
    print ("Lol")

def new_func(ls):
    for i in ls:
        print (i)


def reverseString(s):
    ans = ""

    for i in range(0, len(s)):
        ans += s[len(s) - i - 1]
    return ans

test_func()
test_func()

new_func(['a', 20, 25])

print (reverseString("hello"))