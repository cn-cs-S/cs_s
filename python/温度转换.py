TempStr = input("请输入:")
if TempStr[-1] in ['F', 'f']:
    c = (eval (TempStr[0: -1]) - 32) / 1.8
    print ("温度为", c, "F")
elif TempStr[-1] in ['C', 'c']:
    f = 1.8 * eval(TempStr[0: -1]) + 32
    print("温度为", f, "C")
else:
    print("error")
    print("secondline")