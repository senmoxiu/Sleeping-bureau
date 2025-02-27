#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void Language();
void Init();
void Welcome();
void Login();
void Display();
void Out();
void CunKuan();
void Query();
void ChangePwd();
void Transfer();
void Quit();
void fh();
void kaihu();

typedef struct
{
    char yhm[20];
    int zh;
    int mm;
    float ye;
}aconut;

aconut sj[10];
int yy;//储存选择的语言

void Language()//语言选择
{
    printf("请选择系统语言\n");
    printf("請選擇系統語言\n");
    printf("システム言語を選択します\n");
    printf("Please select the system language\n");
    printf("简体中文:1 繁體中文:2 日本語:3 English:4\n");
    scanf("%d",&yy);
    if(4<yy||yy<1)
    {
        printf("系统错误，请重新启动");
        exit(0);
    }
}

void kaihu()//开户
{
    system("cls");//清屏
    int i,kh,d,f;
    for(i=0;i<10;i++)
    {
        if(sj[i].zh==0)
        {
            kh=i;
            switch(yy)
         {
           case 1:printf("\n请输入用户名；\n");break;
           case 2:printf("\n請輸入用戶名；\n");break;
           case 3:printf("\nユーザー名を入力します:\n");break;
           case 4:printf("\n Please enter the user name:\n");break;
         }
            scanf("%s",sj[kh].yhm);
            sj[kh].zh=rand()%90000+10000;//生成10000~99999之间的随机数
            for(f=0;f<10;f++)
            {
                if(sj[kh].zh==sj[f].zh)//防止生产的随机数与现有账号重合
                {
                    srand((unsigned int)time(NULL));
                    sj[kh].zh=rand()%90000+10000;
                }
            }
            switch(yy)
         {
           case 1:printf("请输入密码\n");break;
           case 2:printf("請輸入密碼\n");break;
           case 3:printf("パスワードをお願いします\n");break;
           case 4:printf("Please enter password\n");break;
         }
            scanf("%d",&sj[kh].mm);
            sj[kh].ye=0;
            for(i=0;i<=10;i++)
        {
            printf("██");
            Sleep(250);
        }
        printf("\n");
        system("pause");//暂停
        system("cls");//清屏
            switch(yy)
         {
           case 1:printf("当前用户信息：\n");
                  printf("==============\n");
                  printf("用户姓名：%s\n",sj[kh].yhm);
                  printf("用户账户：%d\n",sj[kh].zh);
                  printf("用户密码：%d\n",sj[kh].mm);
                  printf("用户余额：%.2f\n",sj[kh].ye);
                  printf("==============\n");break;
           case 2:printf("當前用戶信息:\n");
                  printf("==============\n");
                  printf("用戶姓名：%s\n",sj[kh].yhm);
                  printf("用戶賬戶：%d\n",sj[kh].zh);
                  printf("用戶密碼：%d\n",sj[kh].mm);
                  printf("用戶餘額：%.2f\n",sj[kh].ye);
                  printf("==============\n");break;
           case 3:printf("現在のユーザー情報：\n");
                  printf("=====================\n");
                  printf("ユーザーの名前：%s\n",sj[kh].yhm);
                  printf("ユーザーアカウント：%d\n",sj[kh].zh);
                  printf("ユーザーパスワード：%d\n",sj[kh].mm);
                  printf("ユーザー残高：%.2f\n",sj[kh].ye);
                  printf("=====================\n");break;
           case 4:printf("Current User information:\n");
                  printf("=========================\n");
                  printf("User name：%s\n",sj[kh].yhm);
                  printf("User account：%d\n",sj[kh].zh);
                  printf("User password：%d\n",sj[kh].mm);
                  printf("User balance：%.2f\n",sj[kh].ye);
                  printf("=========================\n");break;
         }
            system("pause");//暂停
            Quit();//退出系统
            break;
        }
    }
    if(i==9)
    {

        switch(yy)
         {
           case 1:printf("账号容量不足,请联系管理员扩容\n");
                  printf("返回上一页？\n");
                  printf("是:1    否:0\n");break;
           case 2:printf("賬號容量不足,請聯繫管理員擴容\n");
                  printf("返回上一頁？\n");
                  printf("是:1    否:0\n");break;
           case 3:printf("アカウント容量が不足していますので、管理者に連絡して拡張してください\n");
                  printf("前のページに戻りますか?\n");
                  printf("はい:1    いいえ:0\n");break;
           case 4:printf("The account capacity is insufficient. Contact the administrator to expand the capacity\n");
                  printf("Back to previous page?\n");
                  printf("Yes :1    No :0\n");break;
         }
        scanf("%d",&d);
        if(d==1)
        {
            Welcome();
        }
        else if(d==0)
        {
            Quit();
        }

    }


}
void Init()//初始化
{
    FILE*fp;
    fp=fopen("睡务局.txt","r");
    int i;
    if(fp==NULL)
        {
        switch(yy)
        {
           case 1:printf("没有文件");break;
           case 2:printf("沒有文件");break;
           case 3:printf("書類がありません");break;
           case 4:printf("No file");break;
        }

        exit(0);
        }
    for(i=0;i<10;i++)
    {
        fscanf(fp,"%s%d%d%f",sj[i].yhm,&sj[i].zh,&sj[i].mm,&sj[i].ye);
        printf("%s %d %d %f\n",sj[i].yhm,sj[i].zh,sj[i].mm,sj[i].ye);
    }
    fclose(fp);
}

void Welcome()//欢迎界面
{
    switch(yy)
        {
           case 1:printf("加载中，请稍后...\n");break;
           case 2:printf("加載中，請稍後...\n");break;
           case 3:printf("ロード中です,少々…\n");break;
           case 4:printf("Loading, please wait...\n");break;
        }
    int i;
    for(i=0;i<=10;i++)
        {
            printf("██");
            Sleep(250);
        }
    int d;
    switch(yy)
        {
           case 1:printf("\n加载完成\n");
                  system("pause");
                  system("cls");
                  printf("\n#################################\n");
                  printf("#                               #\n");
                  printf("#            欢迎使用           #\n");
                  printf("#        1.开户    2.登录       #\n");
                  printf("#                               #\n");
                  printf("#################################\n");;break;
           case 2:printf("\n加載完成\n");
                  system("pause");
                  system("cls");
                  printf("\n#################################\n");
                  printf("#                               #\n");
                  printf("#            歡迎使用           #\n");
                  printf("#        1.開戶    2.登錄       #\n");
                  printf("#                               #\n");
                  printf("#################################\n");;break;
           case 3:printf("\nロード完了\n");
                  system("pause");
                  system("cls");
                  printf("\n#################################\n");
                  printf("#                               #\n");
                  printf("#          ご利用を歓迎         #\n");
                  printf("#    1.口座開設    2.登録       #\n");
                  printf("#                               #\n");
                  printf("#################################\n");;break;
           case 4:printf("\nLoad complete\n");
                  system("pause");
                  system("cls");
                  printf("\n#################################\n");
                  printf("#                               #\n");
                  printf("#         Welcome to use        #\n");
                  printf("#       1.Open an account       #\n");
                  printf("#       2.Log in                #\n");
                  printf("#                               #\n");
                  printf("#################################\n");;break;
        }
    scanf("%d",&d);
    if(d==1)
        kaihu();
    else if(d==2)
        Login();
    else
    {
        printf("请输入正确的选项/n");
        printf("\n");
        system("pause");
        system("cls");
        Welcome();
    }
}
int pos;
void Login()//登录
{
    system("cls");
    int zh;
    int mm;
    int i,j;
    switch(yy)
         {
           case 1:printf("请输入账号\n");break;
           case 2:printf("請輸入賬號\n");break;
           case 3:printf("アカウント入力をお願いします\n");break;
           case 4:printf("Please enter your account number\n");break;
         }
    scanf("%d",&zh);

    switch(yy)
         {
           case 1:printf("请输入密码\n");break;
           case 2:printf("請輸入密碼\n");break;
           case 3:printf("パスワードをお願いします\n");break;
           case 4:printf("Please enter password\n");break;
         }
    scanf("%d",&mm);
    for(j=1;j<=3;j++)
    {

    for(i=0;i<10;i++)
    {
        if(zh==sj[i].zh&&mm==sj[i].mm)
        {
            switch(yy)
         {
           case 1:printf("登录成功\n");break;
           case 2:printf("登錄成功\n");break;
           case 3:printf("ログインできました\n");break;
           case 4:printf("Login successful\n");break;
         }
            pos=i;
            break;
        }
    }
    if(pos==i)
        break;

    if(i==10)
        {
        switch(yy)
         {
           case 1:printf("登录失败，用户名或密码错误\n");break;
           case 2:printf("登錄失敗，用戶名或密碼錯誤\n");break;
           case 3:printf("ログインに失敗したり,ユーザー名やパスワードを間違えたりします\n");break;
           case 4:printf("Login failed because the user name or password is incorrect\n");break;
         }
        }
    switch(yy)
         {
           case 1:printf("请输入账号\n");break;
           case 2:printf("請輸入賬號\n");break;
           case 3:printf("アカウント入力をお願い\n");break;
           case 4:printf("Please enter your account number\n");break;
         }
    scanf("%d",&zh);

    switch(yy)
         {
           case 1:printf("请输入密码\n");break;
           case 2:printf("請輸入密碼\n");break;
           case 3:printf("パスワードをお願い\n");break;
           case 4:printf("Please enter password\n");break;
         }
    scanf("%d",&mm);

        if(j==3)
        {
            switch(yy)
         {
           case 1:printf("失败次数达到3次，请稍后再试\n");break;
           case 2:printf("失敗次數達到3次，請稍後再試\n");break;
           case 3:printf("失敗回数が3回になりましたら,あとでもう一度やってください\n");break;
           case 4:printf("The number of failed attempts reaches 3. Please try again later\n");break;
         }
            exit(0);
            break;
        }
    }
}
void Display()//菜单
{
    system("cls");
    int a;
    switch(yy)
         {
           case 1:printf("菜单加载中，请稍后...\n");break;
           case 2:printf("菜單加載中，請稍後...\n");break;
           case 3:printf("メニューをロード中ですが、少々…\n");break;
           case 4:printf("Menu loading, please wait... \n");break;
         }
    int i;
    for(i=0;i<=10;i++)
        {
            printf("██");
            Sleep(100);
        }
    printf("\n");
    system("pause");
    system("cls");
    switch(yy)
         {
           case 1:printf("\n#################################\n");
                    printf("#              菜单             #\n");
                    printf("#        1.取款                 #\n");
                    printf("#        2.存款                 #\n");
                    printf("#        3.查询账号信息         #\n");
                    printf("#        4.修改密码             #\n");
                    printf("#        5.转账                 #\n");
                    printf("#        6.问题反馈             #\n");
                    printf("#        7.销户                 #\n");
                    printf("#        8.退出系统             #\n");
                    printf("#################################\n");
                    printf("请输入您需要的功能\n");break;
           case 2:printf("\n#################################\n");
                    printf("#              菜單             #\n");
                    printf("#        1.取款                 #\n");
                    printf("#        2.存款                 #\n");
                    printf("#        3.查詢賬號信息         #\n");
                    printf("#        4.修改密碼             #\n");
                    printf("#        5.轉賬                 #\n");
                    printf("#        6.問題反饋             #\n");
                    printf("#        7.銷戶                 #\n");
                    printf("#        8.退出系統             #\n");
                    printf("#################################\n");
                    printf("请請輸入您需要的功能\n");break;
           case 3:printf("\n#################################\n");
                    printf("#            メニュー           #\n");
                    printf("#        1.引き出し             #\n");
                    printf("#        2.預金                 #\n");
                    printf("#        3.口座番号を照会       #\n");
                    printf("#        4.パスワードを変更     #\n");
                    printf("#        5.振替                 #\n");
                    printf("#        6.フィードバック       #\n");
                    printf("#        7.売人                 #\n");
                    printf("#        8.システムをログアウト #\n");
                    printf("#################################\n");
                    printf("ご希望の機能を入力願います\n");break;
           case 4:printf("\n#################################\n");
                    printf("#              menu             #\n");
                    printf("#        1.Withdraw money       #\n");
                    printf("#        2.Savings account      #\n");
                    printf("#        3.Querying Account     #\n");
                    printf("#          Information          #\n");
                    printf("#        4.Change password      #\n");
                    printf("#        5.Transfer             #\n");
                    printf("#        6.Problem feedback     #\n");
                    printf("#        7.Cancel account       #\n");
                    printf("#        8.Exit system          #\n");
                    printf("#################################\n");
                    printf("Please enter the function you need\n");break;
         }
    scanf("%d",&a);
    if(a==1)
        Out();
    else if(a==2)
        CunKuan();
    else if(a==3)
        Query();
    else if(a==4)
        ChangePwd();
    else if(a==5)
        Transfer();
    else if(a==6)
        {
            system("cls");
            switch(yy)
         {
           case 1:printf("请前往重庆工程学院明义楼4楼6号找管理员处理\n");break;
           case 2:printf("請前往重慶工程學院明義樓4樓6號找管理員處理\n");break;
           case 3:printf("重慶工程学院明義楼4階6号に管理人を探して処理してもらいます\n");break;
           case 4:printf("Please go to No.6, 4th Floor, Mingyi Building, Chongqing Institute of Engineering to find the administrator\n");break;
         }
            fh();
        }
    else if(a==7)
        xiaohu();
    else if(a==8)
        Quit();
    else if(a>8||a<1)
    {
       printf("请输入正确的选项\n");
        printf("\n");
        system("pause");
        system("cls");
        Display();
    }
}

void Out()//取款
{
    float q;
    system("cls");
    switch(yy)
         {
           case 1:printf("请输入您要取走的数目\n");break;
           case 2:printf("請輸入您要取走的數目\n");break;
           case 3:printf("お取りになる数を入力していただきます\n");break;
           case 4:printf("Please enter the amount you want to withdraw\n");break;
         }
    scanf("%f",&q);

    if(q<=sj[pos].ye&&q>0)
    {
       sj[pos].ye=sj[pos].ye-q;
       printf("\n取款成功……");
    }

    else if(q<=0)
    {
        switch(yy)
         {
           case 1:printf("请输入正确的取款额\n");break;
           case 2:printf("請輸入正確的取款額\n");break;
           case 3:printf("正しい引き出し額の入力をお願いします\n");break;
           case 4:printf("Please enter the correct withdrawal amount\n");break;
         }
    }
    else if(q>sj[pos].ye)
    {
        switch(yy)
         {
           case 1:printf("余额不足\n");break;
           case 2:printf("餘額不足\n");break;
           case 3:printf("残額が足りません\n");break;
           case 4:printf("Insufficient balance\n");break;
         }
    }
    fh();


}
void CunKuan()//存款
{
    system("cls");
    float q;
    switch(yy)
         {
           case 1:printf("请输入您要存入的数目\n");break;
           case 2:printf("請輸入您要存入的數目\n");break;
           case 3:printf("ご入金される金額を入力願います\n");break;
           case 4:printf("Please enter the amount you want to deposit\n");break;
         }
    scanf("%f",&q);
    if(q>0)
    {
        sj[pos].ye=sj[pos].ye+q;
        printf("\n存款成功……");
    }

    else
    switch(yy)
         {
           case 1:printf("请输入正确的取款额\n");break;
           case 2:printf("請輸入正確的存款額\n");break;
           case 3:printf("正しい預金額の入力をお願いします\n");break;
           case 4:printf("Please enter the correct deposit amount\n");break;
         }

    fh();
}
void Query()//查询
{
    system("cls");
    switch(yy)
         {
           case 1:printf("当前用户信息：\n");
                  printf("==============\n");
                  printf("用户姓名：%s\n",sj[pos].yhm);
                  printf("用户账户：%d\n",sj[pos].zh);
                  printf("用户密码：%d\n",sj[pos].mm);
                  printf("用户余额：%.2f\n",sj[pos].ye);
                  printf("==============\n");break;
           case 2:printf("當前用戶信息:\n");
                  printf("==============\n");
                  printf("用戶姓名：%s\n",sj[pos].yhm);
                  printf("用戶賬戶：%d\n",sj[pos].zh);
                  printf("用戶密碼：%d\n",sj[pos].mm);
                  printf("用戶餘額：%.2f\n",sj[pos].ye);
                  printf("==============\n");break;
           case 3:printf("現在のユーザー情報：\n");
                  printf("=====================\n");
                  printf("ユーザーの名前：%s\n",sj[pos].yhm);
                  printf("ユーザーアカウント：%d\n",sj[pos].zh);
                  printf("ユーザーパスワード：%d\n",sj[pos].mm);
                  printf("ユーザー残高：%.2f\n",sj[pos].ye);
                  printf("=====================\n");break;
           case 4:printf("Current User information:\n");
                  printf("=========================\n");
                  printf("User name：%s\n",sj[pos].yhm);
                  printf("User account：%d\n",sj[pos].zh);
                  printf("User password：%d\n",sj[pos].mm);
                  printf("User balance：%.2f\n",sj[pos].ye);
                  printf("=========================\n");break;
         }
    fh();
}

int x;//记录循环次数
void ChangePwd()//修改密码
{
    system("cls");
    int i;
    int mm;
    int mm1;
    int mm2;
    if(x==3)
    {
        switch(yy)
         {
           case 1:printf("密码错误次数达到3次，系统自动退出\n");break;
           case 2:printf("密碼錯誤次數達到3次，系統自動退出\n");break;
           case 3:printf("パスワードエラーが3回,自動的にログアウトします\n");break;
           case 4:printf("If the password is incorrect for three consecutive times, the system automatically exits\n");break;
         }
        Quit();
    }
    switch(yy)
         {
           case 1:printf("请输入原密码：");break;
           case 2:printf("請輸入原密碼：");break;
           case 3:printf("元のパスワードをお願いします:");break;
           case 4:printf("Please enter the old password:");break;
         }
    scanf("%d",&mm);
    if(mm==sj[pos].mm)
    {
       for(i=1;i<=3;i++)
       {
        switch(yy)
         {
           case 1:printf("\n请输入新密码：");break;
           case 2:printf("\n請輸入新密碼：");break;
           case 3:printf("\n新しいパスワードをお願いします:");break;
           case 4:printf("\n Please enter a new password:");break;
         }
        scanf("%d",&mm1);
        switch(yy)
         {
           case 1:printf("\n请再次输入：");break;
           case 2:printf("\n請再次輸入：");break;
           case 3:printf("\nもう一度入力をお願いします：");break;
           case 4:printf("\n Please enter again:");break;
         }
        scanf("%d",&mm2);
        if(mm1==mm2)
        {
            sj[pos].mm=mm1;
            switch(yy)
         {
           case 1:printf("密码修改成功，请重新登录\n");break;
           case 2:printf("密碼修改成功，請重新登錄\n：");break;
           case 3:printf("パスワードの変更に成功しました,再ログインをお願いします\n：");break;
           case 4:printf("The password is changed successfully. Please log in again\n:");break;
         }
            Quit();
        }
        else
        {
            switch(yy)
         {
           case 1:printf("两次密码不一致，请重新输入");break;
           case 2:printf("兩次密碼不一致，請重新輸入");break;
           case 3:printf("2回パスワードが一致しません,再入力してください");break;
           case 4:printf("The two passwords are inconsistent. Please re-enter them");break;
         }
        }
        if(i==3)
        {
            switch(yy)
         {
           case 1:printf("密码错误达到3次");break;
           case 2:printf("密碼錯誤達到3次");break;
           case 3:printf("パスワードエラーは3回でした");break;
           case 4:printf("Password errors reached 3 times:");break;
         }
            fh();
        }
       }
    }
    else
    {
        switch(yy)
         {
           case 1:printf("请输入正确的密码");break;
           case 2:printf("請輸入正確的密碼");break;
           case 3:printf("正しいパスワードをお願いします");break;
           case 4:printf("Please enter the correct password");break;
         }
        x++;
        ChangePwd();//自己调用自己来循环
    }

}
void Transfer()//转账
{
    system("cls");
    int zh;
    float je;
    int i,j;
    int zz;
    switch(yy)
         {
           case 1:printf("请输入账号\n");break;
           case 2:printf("請輸入賬號\n");break;
           case 3:printf("アカウント入力をお願い\n");break;
           case 4:printf("Please enter your account number\n");break;
         }
    scanf("%d",&zh);
    for(i=0;i<10;i++)
    {
        if(zh==sj[i].zh)
        {
            switch(yy)
         {
           case 1:printf("账户正确\n");break;
           case 2:printf("賬戶正確\n");break;
           case 3:printf("口座が正しいです\n");break;
           case 4:printf("Correct account\n");break;
         }
            zz=i;
             switch(yy)
         {
           case 1:printf("请输入您转出的金额\n");break;
           case 2:printf("請輸入您轉出的金額\n");break;
           case 3:printf("送金された金額を入力していただきます\n");break;
           case 4:printf("Please enter the amount you are transferring\n");break;
         }
            scanf("%f",&je);
            if(je<=sj[pos].ye&&je>0)
            {
            sj[pos].ye=sj[pos].ye-je;
            sj[zz].ye=sj[zz].ye+je;
            fh();
            }

            else if(je<0)
            {
                switch(yy)
              {
                case 1:printf("请输入正确的取款额\n");break;
                case 2:printf("請輸入正確的取款額\n");break;
                case 3:printf("正しい引き出し額の入力をお願いします\n");break;
                case 4:printf("Please enter the correct withdrawal amount\n");break;
              }
            }
            else if(je>sj[pos].ye)
            {
                switch(yy)
              {
                case 1:printf("余额不足\n");break;
                case 2:printf("餘額不足\n");break;
                case 3:printf("残額が足りません\n");break;
                case 4:printf("Insufficient balance\n");break;
              }
            }
            fh();

        }

    }
    if(i==10)
        {
            switch(yy)
         {
           case 1:printf("账号输入错误\n");break;
           case 2:printf("賬號輸入錯誤\n");break;
           case 3:printf("アカウント入力ミス\n");break;
           case 4:printf("Account input error\n");break;
         }
            fh();
        }

}
void xiaohu()//销户
{
    system("cls");
    int d;
    printf("您确定要销户吗？\n");
    switch(yy)
         {
           case 1:printf("是:1    否:0\n");break;
           case 2:printf("是:1    否:0\n");break;
           case 3:printf("はい:1    いいえ:0\n");break;
           case 4:printf("Yes :1    No :0\n");break;
         }
    scanf("%d",&d);
    if(d==1)
    {
        sj[pos].yhm[20]="/0";
        sj[pos].zh=0;
        sj[pos].mm=0;
        sj[pos].ye=0;
    }
    system("cls");
    switch(yy)
        {
           case 1:printf("加载中，请稍后...");break;
           case 2:printf("加載中，請稍後...");break;
           case 3:printf("ロード中です,少々…");break;
           case 4:printf("Loading, please wait...");break;
        }
    int i;
    for(i=0;i<=10;i++)
        {
            printf("██");
            Sleep(250);
        }
    printf("\n");
    Quit();

}
void Quit()//退出系统
{
    printf("\n");
    system("pause");
    system("cls");
    switch(yy)
         {
           case 1:printf("系统退出中.....\n");break;
           case 2:printf("系統退出中.....\n");break;
           case 3:printf("システムログアウト中.....\n");break;
           case 4:printf("The system is exiting.....\n");break;
         }
    int i;
    for(i=0;i<=10;i++)
        {
            printf("██");
            Sleep(250);
        }
    printf("\n");
    system("pause");
    FILE*fp;
    fp=fopen("睡务局.txt","w");
    for(i=0;i<10;i++)
    {
        fprintf(fp,"%s %d %d %f\n",sj[i].yhm,sj[i].zh,sj[i].mm,sj[i].ye);
        printf("%s %d %d %f\n",sj[i].yhm,sj[i].zh,sj[i].mm,sj[i].ye);
    }

    fclose(fp);
    exit(0);
}
void fh()//返回菜单
{
    printf("\n");
    system("pause");
    system("cls");
    int d;
    switch(yy)
         {
           case 1:printf("您要返回菜单吗？\n");break;
           case 2:printf("您要返回菜單嗎？\n");break;
           case 3:printf("メニューに戻りますか。n");break;
           case 4:printf("Do you want to go back to the menu?\n");break;
         }
    switch(yy)
         {
           case 1:printf("是:1    否:0\n");break;
           case 2:printf("是:1    否:0\n");break;
           case 3:printf("はい:1    いいえ:0\n");break;
           case 4:printf("Yes :1    No :0\n");break;
         }
    scanf("%d",&d);
    if(d==1)
        Display();
    else if(d==0)
        Quit();
}
int main()
{
    Language();
    Init();
    Welcome();
    Login();
    Display();

    return 0;
}
