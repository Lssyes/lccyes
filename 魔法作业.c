#include <stdio.h>
struct player
{
    int num;
    char name[20];
    float power;
    float magic;
    float powAmag;
    float score[3];
}stu[10];


int ave(struct player stu[] ,struct File *fp)
{


    for (int i = 0; i < 10; i++){
        stu[i].powAmag = 0;
        stu[i].powAmag += stu[i].power + stu[i].magic;
        fprintf(fp,"玩家%d\t 力量：%.2f\t 魔法：%.2f\t 总能力值：%.2f\n",i+1,stu[i].power, stu[i].magic,stu[i].powAmag);
//        min = (min<stu[i].powAmag)?min:stu[i].powAmag;
        

    }
    
    fputs("*****************************************************\n",fp);
    

    return 0;
}
void find(struct player stu[],struct File *fp)
{
    int i;
    float ave[10];
    int t = 0;
    int min = 0;
    for (int j = 0; j < 10; j++){
        ave[j]=stu[j].powAmag;
    }
    
    
    for (i = 0; i < 10; i++)
    {
//        printf("%.2F\t",ave[i]);
        if (ave[min] > ave[i])
        {
            min = i;
            t = i;
        }
    }
    fprintf(fp,"能力值最低的玩家的数据为：\n玩家%d\t 力量：%.2f\t 魔法：%.2f\t 总能力值：%.2f\n!",t+1,stu[t].power, stu[t].magic,stu[t].powAmag);
}



int main(){

    char path[100] = {"/Users/apple/Desktop/LiangShiHuiHomework"};
    FILE *fp = fopen(path,"w");
    if(fp==NULL)
        {
         printf("读取文件失败！\n");
         exit(0);
        }
    
    printf("请输入十名玩家的力量和魔法：\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &stu[i].num);
        scanf("%s", stu[i].name);
        scanf("%f", &stu[i].power);
        scanf("%f", &stu[i].magic);
    }
    fputs("************************************\n",fp);
    ave(stu,fp);
    find(stu,fp);
    fclose(fp);
    
    FILE *fpr = fopen(path,"r");
    char buff[255];
    while (1) {
        fgets(buff, 255, (FILE*)fpr);
         if(feof(fpr)) break;
        printf("%s", buff );
    }

    fclose(fpr);
    return 0;
}

