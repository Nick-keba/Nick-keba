#include <stdio.h>
#include <string.h>
#include <time.h>


int main()
{
    
    //时间函数的定义:起始时间/终止时间
    clock_t Start_time,End_time;
    double duration;
    
    FILE *fp;/*文件指针*/
    
    
    //定义字符串
    char buffer[501]={0};/*存贮读取文件一行的字符*/
	char str[501]={0};
	//定义要查找的子字符串
	char key_str[41]={0};
//	printf("输入字符串(50个字符)\n");
//	scanf("%s",str);
	printf("要查找的字符串\n");
	scanf("%s",key_str);
	
	//记录匹配的次数
	int count=0;
	
	Start_time=clock();
	
	//文件指针指向的文件地址
	fp=fopen("D:\\line.txt","r");
	//判断文件打开是否成功:
	if(fp==NULL) 
	  {
          perror("打开失败:"); 
		     
		  return 0;
	  }

	
	//判断文件是否读完
	 while(!feof(fp)) 
	 
 {
	 
	 while(fgets(buffer,sizeof(buffer),fp)!=NULL)/*读取文件一行的字符*/
    
    {
	    str[501]=buffer[501];
	
	
	
	    //遍历字符串
	    for(int i=0;i<strlen(str);i++)
	    {
	        //在字符串中找到和要找的字符串中的第一个字符相同的字符的位置
	        if(str[i]==key_str[0])
	    {
	        //记录当前字符串中找到的与子串中的第一个字符相同字符的位置,并保存现场
	        int temp_i=i;
	        //子串中的字符循坏变量
	        int j=0;
	        //记录相同字符数的长度
	        int length=0;
	        
	        //找到相同字符位置后依次向后进行比对'\0'字符串的结束标志,无需比对
	        while(str[temp_i]==key_str[j]&&str[temp_i]!='\0'&&key_str[j]!='\0')
	        {
	            //每找到相同的字符后,相同数长度+1
	            length++;
	            //依次向后进行比对
	            temp_i++;
	            j++;
	        }
	            
	       //判断比对相同的字符长度 是否与子串的长度一致,如果一致的话,就找到一个子串
	       if(length==strlen(key_str))
	       {
	           //子串的匹配次数+1
	           count++;
	       }
	    }
	    
	}
	
	
	
	printf("匹配的次数:%d\n",count);

	End_time=clock();
	duration=(double)(End_time-Start_time)/CLOCKS_PER_SEC;
	
	printf("耗时%fs\n",duration);
    
    
    printf("Hello World");

     }
 }
    
    
    fclose(fp);
   
    return 0;

}
