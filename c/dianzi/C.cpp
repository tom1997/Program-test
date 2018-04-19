
    Date_Load();
    do{
        printf("\n\n\n\tFunction choose:");
        printf("\n\t1.Read");
        printf("\n\t2.Append");
        printf("\n\t3.Delete");
        printf("\n\t4.Quit");
        printf("\n\n");
        printf("\tChoice:");
        ch=getche();
        switch(ch)
        {
            case '1':     /*阅读留言内容*/
                if(front==rear)
                {
                    printf("\n\tNo records.");
                    break;;
                }
                p=event_front->next;
                while(getch()!=0x1b&&p!=NULL)
                {
                    Data_Show(p);
                    p=p->next;
                }
                break;
            case '2':        /*添加留言记录*/
                p=malloc(sizeof(struct record));
                Data_Input(p);
                event_end->next=p;
                event_end=p;
                while(getch()!=0x1b&&(front+1)!=rear)
                {
                    p=malloc(sizeof(struct record));
                    Data_Input(p);
                    event_end->next=p;
                    event_end=p;
                }
                break;
            case '3':
                p=event_head.next;    /*删除留言记录*/
                event_head.next=p->next;
                free(p);
                exit(0);
                break;
            case '4':
                printf("\n\tDo you want to save e_note:(y/n)");
                ch=getch();
              if(ch=='y')
                    Data_Save(event_head.next);
                fclose(fp);
                exit(0);
            default:
                printf("Please choose num 1--4\n");
        }
    }
    while(1);
}