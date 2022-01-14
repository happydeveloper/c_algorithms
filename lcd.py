#!/usr/bin/env python
# -*- coding: utf-8 -*-
#변수 초기화
inputNumber = "123456789012345"
top = 0
bottom = 0
middle = 0
digit = [" # ", " # ","|# "," #|","|#|"]

#문자를 초기화
def initDigit():
    digit[0] = " # "
    digit[1] = " # "
    digit[2] = "|# "
    digit[3] = " #|"
    digit[4] = "|#|"

#문자를 대입
def makeDigit(x):
    linestr = ""
    whitestr = ""
    for i in range(x):
        whitestr += " "
        linestr  += "-"
    for i in range(len(digit)):
        if( i == 1):
            digit[i] = digit[i].replace('#',linestr)
        else :
            digit[i] = digit[i].replace('#',whitestr)



#기준 정하기  / 위  / 중간 / 아래
def setCriterion(x):
    global top
    global middle
    global bottom
    top = 1
    middle = 2+x
    bottom = 3+(x*2)


#문자를 LCD 타입으로 표시하기    
def textToGraphic(x, line) :
    #1
    if(x == 1 and ((line == top) or (line == middle) or (line == bottom))) :
        return digit[0]
    if(x == 1 and ((line != top) or (line != middle) or (line != bottom))) :
        return digit[3]
    #2
    if(x == 2 and ((line == top) or (line == middle) or (line == bottom))) :
        return  digit[1]
    if(x == 2 and (top < line < middle)) :
        return  digit[3]
    if(x == 2 and (middle < line < bottom)) :
        return  digit[2]
    #3
    if(x == 3 and ((line == top) or (line == middle) or (line == bottom))) :
        return  digit[1]
    if(x == 3 and ((line != top) or (line != middle) or (line != bottom))) :
        return  digit[3]
    #4
    if(x == 4 and (line == top or line == bottom)) :
        return  digit[0]
    if(x == 4 and (top < line < middle)) :
        return  digit[4]
    if(x == 4 and (line == middle)) :
        return  digit[1]
    if(x == 4 and (middle < line < bottom )) :
        return  digit[3]
    #5
    if(x == 5 and (line == top or line == middle or line == bottom)) :
        return  digit[1]
    if(x == 5 and (top < line < middle)) :
        return  digit[2]
    if(x == 5 and (middle < line < bottom)) :
        return  digit[3]
    #6
    if(x == 6 and (line == top or line == middle or line == bottom)) :
        return  digit[1]
    if(x == 6 and (top < line < middle)) :
        return  digit[2]
    if(x == 6 and (middle < line < bottom)) :
        return  digit[4]
    #7
    if(x == 7 and (line == top)) :
        return digit[1]
    if(x == 7 and (line == middle or line == bottom)) :
        return digit[0]
    if(x == 7 and (top < line < bottom)) :
        return digit[3]
    #8
    if(x == 8 and (line == top or line == middle or line == bottom)) :
        return  digit[1]
    if(x == 8 and (line != top or line != middle or line != bottom)) :
        return  digit[4]
    #9
    if(x == 9 and (line == top or line == middle or line == bottom)) :
        return  digit[1]
    if(x == 9 and (top < line < middle)) :
        return  digit[4]
    if(x == 9 and (middle < line < bottom)) :
        return  digit[3]
    #0
    if(x == 0 and (line == top or line == bottom)) :
        return  digit[1]
    if(x == 0 and (line == middle)) :
        return digit[0]
    if(x == 0 and (line != top or line != middle or line != bottom)) :
        return  digit[4]
    else :
        return ""

#LCD display    
def lcdDisplay(x):
    setCriterion(x) #기준라인 정하기
    line=[]
    nu = (x * 2)+3
    for z in range(nu):
        line.append("")
    initDigit() # 문자 초기화
    makeDigit(x)# 대입 문자 만들기

    digitnumber = len(inputNumber) #입력숫자의 길이 할당
    lineNumber = len(line) #라인수 할당
    for i in range(digitnumber):
        for j in range(lineNumber):
            line[j] += ' '+textToGraphic(int(inputNumber[i]), int(j+1))

    for j in range(lineNumber):
        print line[j]

#문자열이, 숫자(정수/실수)인지, 문자인지 체
def isNumber(s):
    try:
        float(s)
        return True
    except ValueError:
        print "숫자가 아닌 문자열이 입력 되었습니다."
    return False

#입력삽에 범위 검사
def isRange(s, n):
    if((1<= int(s) < 10) != True):
        print "첫번째 입력된 숫자가 범위를 벗어났습니다."
        return False
    if((9 < len(n))):
        print "두번째 입력된 숫자가 범위를 벗어났습니다."
        return False   
    return True


#입력창
def inputInterface():
    arg1 = 1
    arg2 = 1
    prompt = """
        첫번쨰 숫자를 문자을 표시하는 크기( 1<= s < 10 )를 의미
        두번째 숫자는 n은 출력될 숫자( 0<= n <= 99,999,999 )를 의미
        0 이 두 개 입력된 줄이 있으면 입력이 종료
        입력 예
        2 12345
        3 67890
        0 0

        Enter nuber : """

    while (arg1 != 0 or arg2 != 0) : #종료 조건
        print prompt
        arg0 = raw_input()
        tmp = arg0.split()
        if(len(tmp) != 2): #유효성 체크 1
            print("문자를 2개 입력하세요")
        else :
            if(isNumber(tmp[0]) and isNumber(tmp[1])): #유효성 체크 2
                arg1 = int(tmp[0])
                arg2 = tmp[1]
                if(arg1 == 0 and int(arg2) == 0): #while 종료 조건
                    break;
                if(isRange(tmp[0], tmp[1])): #유효성 체크 3
                    if(arg1!= 0):
                        global inputNumber
                        inputNumber = arg2
                        lcdDisplay(arg1)



inputInterface()