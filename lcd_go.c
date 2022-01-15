/*
 *
 File Name : echo_number_output_version220115_002.c
 
 Description :
 
 Algorithm Problem - 요약 - 표준 입력으로부터 두 수를 여러 줄 입력 받는다.0 0를 입력받으면 입력을 종료한다. 그리고 표준 출력으로 입력받은 값의 두번째 값을 출력한다. 첫번째 입력은 사이즈의 입력이고 두번째 입력을 사이즈에 따른 세븐세그먼트 양식으로 출력한다 ...

 Public fuctions:
 
 Notes:
 
 Authors : Goru Kang
 Start Date : 13 Jan 13
 Modified Date : 14 Jan 15
 REF, NO, VERSION, DATE, WHO, DETAIL
 - , 001, 002, 15JAN99, GK, Adding Comments forms
 *
*/
#include <stdio.h>

unsigned char DecTo7Seg(int decimalN)
{
  unsigned char flags;
  flags = 0x00;
  switch(decimalN)
    {
        case 0: flags=0x7e; break;
        case 1: flags=0x06; break;
        case 2: flags=0x5b; break;
        case 3: flags=0x4f; break;
        case 4: flags=0x27; break;
        case 5: flags=0x6d; break;
        case 6: flags=0x3d; break;
        case 7: flags=0x46; break;
        case 8: flags=0x7f; break;
        case 9: flags=0x67; break;
        default: flags=0x00; break;
    }
    //printf("The flag is %x\n",flags);
    return flags;
}

int main() 
{
int i, j;
unsigned char flags;
int size; //The variable for the input size (1~9)
char str[20]; //The variable for the input number (0~99,999,999)
int D[8];//The variable for input number to decomposite decialN
int length_str, lines;
int valid_str;

    printf("Please input the number s and n, where 1<=s<10, 0<=n<=99,999,999\n");
    printf("Example : \n");
    printf("1 12345\n");
    printf("2 67890\n");
    printf("0 0\n");

    //Initialize a variable for line counter
    lines = 0;
    while(1)
    {
        //Input of size and string number
        scanf("%d %s",&size,str);

        //exception_1 : The interrupt by a inputting of the end message
        if((size == 0)&&(str[0] == '0'))
        {
            printf("The input was interrupted.\n");
            break;
        }
        //exception_2 : Invalid input on a variable of size
        if(size<1 || size >9) printf("Invalid input : The size should will be inputted as the enable rnage from 1 to 9 (size : 1~9).\n");
        
        //exception_3 : Invalid input on variable of size
        //Converting from str to a one digit numbers
        //Counting length of str[] and input lines
        for(i=0;str[i] != '\0';i++)
        {
            D[i] = str[i] -'0';
            printf("D[%d]=%d ",i,D[i]);
            length_str = i+1;

            //Testing a validity of a valiable
            valid_str = 0; //Initialize a valiable to confirm a valid test of inputs
            if(str[i]>47 && str[i]<58)
            {
                valid_str = 1;
            }
            else
            {
                valid_str = 0;
                str[i+1] = '\0'; //A Trick of escaping for loop
            }
            //printf("Debuging check: valiable valid_str : %d\n", valid_str);
        }
    
        if(length_str>8 || size >9 || valid_str != 1) printf("Invalid input : The size should will be inputted as the enable rnage from 0 to 99,999,999 (size : 0~99,999,999).\n");
        
        printf("\nYour inputs are %d %s.\n", size, str);
        
        //The valid condition to execute the manipulation of data
        if(size>=1 && size<10 && length_str <=8 && valid_str ==1)
        {
            lines = lines + 1; //Counting input lines
            int canv_row, canv_col;
            canv_row = 2*size + 3;
            canv_col = (size + 2)*length_str;
            char canvas[canv_row][canv_col]; //Creating and initializing canvas array
            int characters=0;
            int onCanvas_characters_position=0; // a position of character on canvas
            
            //Decoding digits characters in this line and writing digits chacters as seven segments on canvas
            for(characters=0;characters<length_str;characters++)
            {
                flags=DecTo7Seg(D[characters]);
                //print7seg(size,flags); //writing a character on output array
                int row, col;
                int seg[7];
                row = 2*size + 3;
                col = size + 2;
                char output[row][col];
                
                //Decoding flags parameters
                for(i=0;i<7;i++)
                {
                    seg[i] = flags & (0x40>>i);
                    seg[i] = seg[i] >> (6-i);
                    //printf("The seg[%d]=%d\n",i,seg[i]);
                }
                
                //Initialize output array
                for(i=0;i<row;i++)
                {
                    for(j=0;j<col;j++)
                        output[i][j]=' ';
                }
                //Input output array on segement number
                for(i=0;i<row;i++)
                {
                    for(j=0;j<col;j++)
                    {
                        if(i==0)
                        {
                            if(seg[0]==1) //seg[0] ==seg.1
                            {
                                output[i][j]= '-';
                                if(j==0) output[i][j]=' ';
                                if(j==col-1) output[i][j]=' ';
                            }
                            else
                            {
                                output[i][j]=' ';
                            }
                        }
                        //
                        else if(i!=0 && i<size+1)
                        {
                            if(seg[1]==1 || seg[5]==1) //seg[1]==seg.2, seg[5]==seg.6
                            {
                                output[i][j]= ' ';
                                if(j==0 && seg[1]==1) output[i][j]='|';
                                if(j==col-1 && seg[5]==1) output[i][j]='|';
                            }
                            else
                            {
                                output[i][j]=' ';
                            }
                        }
                        //
                        else if(i==size+1)
                        {
                            if(seg[6]==1)
                            { //seg[6]==seg.7
                                output[i][j]= '-';
                                if(j==0) output[i][j]=' ';
                                if(j==col-1) output[i][j]=' ';
                            }
                            else
                            {
                                output[i][j]=' ';
                            }
                        }
                        //
                        else if(i!=row-1 && i>size+1)
                        {
                            if(seg[2]==1 || seg[4]==1) //seg[2]==seg.3,seg[4]==seg.5
                            {
                                output[i][j]= ' ';
                                if(j==0 && seg[2]==1) output[i][j]='|';
                                if(j==col-1 && seg[4]==1) output[i][j]='|';
                            }
                            else
                            {
                                output[i][j]=' ';
                            }
                        }
                        //
                        else if(i==row-1)
                        {
                            if(seg[3]==1)
                            { //seg[3]==seg.4
                                output[i][j]= '-';
                                if(j==0) output[i][j]=' ';
                                if(j==col-1) output[i][j]=' ';
                            }
                            else
                            {
                                output[i][j]=' ';
                            }
                        }
                    }
                }
                //move a character frome output array to canvas array
                onCanvas_characters_position=characters*(size+2); //calculation a characters position on canvas
                for(i=0;i<row;i++)
                {
                    for(j=0;j<col;j++)
                    {
                    canvas[i][onCanvas_characters_position+j]=output[i][j];
                    }
                }
            }
            //print canvas array
            for(i=0;i<canv_row;i++)
            {
                for(j=0;j<canv_col;j++)
                    printf("%c",canvas[i][j]);
                printf("\n");
            }
        }
    printf("Please input the next number s and n.\n");
    printf("When the input number are 0 0, the input will be interupted.\n");

    }
    printf("The escaped.\n");
    printf("Bye!\n");
    
    return 0;
}

/*
inline int print7seg(int size, unsigned char flags)
{
    int row, col;
    int i, j;
    int seg[7];
    row = 2*size + 3;
    col = size + 2;
    char output[row][col];
    
    //Decoding flags parameters
    for(i=0;i<7;i++)
    {
        seg[i] = flags & (0x40>>i);
        seg[i] = seg[i] >> (6-i);
        printf("The seg[%d]=%d\n",i,seg[i]);
    }
    
    //Initialize output array
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            output[i][j]=' ';
    }
    //Input output array on segement number
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==0)
            {
                if(seg[0]==1) //seg[0] ==seg.1
                {
                    output[i][j]= '-';
                    if(j==0) output[i][j]=' ';
                    if(j==col-1) output[i][j]=' ';
                }
                else
                {
                    output[i][j]=' ';
                }
            }
            //
            else if(i!=0 && i<size+1)
            {
                if(seg[1]==1 || seg[5]==1) //seg[1]==seg.2, seg[5]==seg.6
                {
                    output[i][j]= ' ';
                    if(j==0 && seg[1]==1) output[i][j]='|';
                    if(j==col-1 && seg[5]==1) output[i][j]='|';
                }
                else
                {
                    output[i][j]=' ';
                }
            }
            //
            else if(i==size+1)
            {
                if(seg[6]==1)
                { //seg[6]==seg.7
                    output[i][j]= '-';
                    if(j==0) output[i][j]=' ';
                    if(j==col-1) output[i][j]=' ';
                }
                else
                {
                    output[i][j]=' ';
                }
            }
            //
            else if(i!=row-1 && i>size+1)
            {
                if(seg[2]==1 || seg[4]==1) //seg[2]==seg.3,seg[4]==seg.5
                {
                    output[i][j]= ' ';
                    if(j==0 && seg[2]==1) output[i][j]='|';
                    if(j==col-1 && seg[4]==1) output[i][j]='|';
                }
                else
                {
                    output[i][j]=' ';
                }
            }
            //
            else if(i==row-1)
            {
                if(seg[3]==1)
                { //seg[3]==seg.4
                    output[i][j]= '-';
                    if(j==0) output[i][j]=' ';
                    if(j==col-1) output[i][j]=' ';
                }
                else
                {
                    output[i][j]=' ';
                }
            }
        }
    }
    //print output array
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%c",output[i][j]);
        printf("\n");
    }
    return 0;
    
}
*/
/*
 Previous File Name: None
 Comment 1: 2022year January 13 Starting to solve an algorithm problem from Duru Kang.
 참조 내용 1: 2022년 1월 13일 두루로 부터 코딩문제 풀이 작성 시작.
 Modified File Name: echo_number_output.c
 */
/*
 Previous File Name: echo_number_output.c
 Change content 1: Modified indentation to improve legibility
 수정 내용 1: 가독성 향상을 위한 들여쓰기 수정
 
 Change content 2: Change the position of the output statement after input to improve readability (changed after exception handling)
 수정 내용 2: 가독성 향상을 위한 입력 후 출력문 위치 변경(예외처리 이후로 변경)
 
 Change content 3: Adding a return value int (integer) type at end of main function code
 수정 내용 3: main 함수 정수형(int) 반환값 추가
 
 Change content 4: Adding tail comments of historical changes contents
 수정 내용 4: 이력적인 변경의 꼬리 주석 추가
 
 Change content 5: Adding Head comments of this code file
 수정 내용 5: 현재 파일에 대한 머리말 주석 추가
 Modified File Name: echo_number_output_version220115_001.c
 */
/*
 Previous File Name: echo_number_output_version220115_001.c
 Change content 6: Inserting the code which print 7 segment on output and canvas to move output array to canvas array easily. (To move array data directly without using pointer)
 수정 내용 6: 쉽게 character가 작성하되는 output 배열에서 canvas array로 이동 후 출력하기 위해서 main function안에 7segment 출력 함수 직접 코딩해서 넣음. (포인터 사용하지 않고 직접 배열 데이타 이동하기 위함.)
 Modified File Name: echo_number_output_version220115_002.c
 */

