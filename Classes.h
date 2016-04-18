#ifndef Classes
#define Classes

class Mmap
{
public:
    int **mas;
    int n, m;

    Mmap(int,int);
    void Generate();
    friend std::ostream& operator<<(std::ostream& , Mmap&);
    //~Mmap();
};
std::ostream& operator<<(std::ostream& out, Mmap& map)
    {
        for(int i(0); i<map.n; out<<'\n',i++)
		for(int j(0); j<map.m;out<<' ', j++)
		    out<<map.mas[i][j];

        out<<'\n';
        return out;
    }

class Hero
{
public:
    int n,m,id;

    Hero(){;};
    virtual void Put(Mmap&);
    virtual void Move(Mmap&);
    friend bool operator ==(Hero,Mmap);
};

class Fly:public Hero
{
public:
    void Put(Mmap&);
    void Move(Mmap&);
};

class Tp:public Hero
{
public:
    void Put(Mmap&);
    void Move(Mmap&);
};

class Speed:public Hero
{
public:
    void Put(Mmap&);
    void Move(Mmap&);
};

class MGame
{
    Mmap *map;
    Hero *hero;
    Fly *fly;
    Tp *tp;
    Speed *speed;
    int h, f,t,s;

public:
    MGame(int, int,int,int);
    void Turn();
    void Check();
    void SaveF();
    void LoadF();
};

Mmap::Mmap(int n, int m)
{
    this->n=n-1;
    this->m=m-1;
    mas=new int*[n];
    for(int i(0); i<n; ++i)
        mas[i]=new int [m];
}

void Mmap::Generate()
{
    //srand(time(NULL));
    for(int i(0); i<n; ++i)
        for(int j(0); j<m; ++j)
        {
            int c=rand()%10;
            if(c>=0&&c<=6)
                mas[i][j]=0;
            if(c>=7&&c<=9)
                mas[i][j]=1;
        }
}

/*Mmap::~Mmap()
{
    for(int i(0); i<n; ++i)
        delete[]mas[i];
    delete[]mas;
}*/

void Hero::Put(Mmap& obj)
{
    int x,y;
    id=2;
    bool create=false;
    while(!create)
    {
        x=rand()%obj.n;
        y=rand()%obj.m;

        if(obj.mas[x][y]==0)
        {
            this->n=x;
            this->m=y;
            obj.mas[x][y]=2;
            create =true;
        }
    }
}
void Hero::Move(Mmap& obj)
{
    if(this->n>=0||this->m>=0)
    {
        int x,y,k;
        x=this->n;
        y=this->m;
        bool move=false;
        while(!move)
        {
            k=rand()%4+1;

            switch (k)
            {
                case 1:
                    if(this->n>0&&obj.mas[this->n-1][this->m]==0)
                        this->n--;
                break;

                case 2:
                    if(this->m<obj.m&&obj.mas[this->n][this->m+1]==0)
                        this->m++;
                break;

                case 3:
                    if(this->n<obj.n&&obj.mas[this->n+1][this->m]==0)
                        this->n++;
                break;

                case 4:
                    if(this->m>0&&obj.mas[this->n][this->m-1]==0)
                        this->m--;
                break;
            }

            if(obj.mas[this->n][this->m]==0)
            {
                obj.mas[x][y]=0;
                obj.mas[this->n][this->m]=2;
                move =true;
            }
        }
    }
}
void Fly::Put(Mmap& obj)
{
    int x,y;
    id=3;
    bool create=false;
    while(!create)
    {
        x=rand()%obj.n;
        y=rand()%obj.m;

        if(obj.mas[x][y]==0)
        {
            this->n=x;
            this->m=y;
            obj.mas[x][y]=3;
            create =true;
        }
    }
}
void Fly::Move(Mmap& obj)
{
    if(this->n>=0||this->m>=0)
    {
        int x,y,k;
        x=this->n;
        y=this->m;
        bool move=false;
        while(!move)
        {
            k=rand()%4+1;

            switch (k)
            {
                case 1:
                    if(this->n>1&&obj.mas[this->n-1][this->m]==1&&obj.mas[this->n-2][this->m]==0)
                        n=n-2;
                    else if(this->n>0&&obj.mas[this->n-1][this->m]==0)
                        this->n--;
                break;

                case 2:
                    if(this->m<obj.m-1&&obj.mas[this->n][this->m+1]==1&&obj.mas[this->n][this->m+2]==0)
                        m=m+2;
                    else if(this->m<obj.m&&obj.mas[this->n][this->m+1]==0)
                        this->m++;
                break;

                case 3:
                    if(this->n<obj.n-1&&obj.mas[this->n+1][this->m]==1&&obj.mas[this->n+2][this->m]==0)
                        n=n+2;
                    else if(this->n<obj.n&&obj.mas[this->n+1][this->m]==0)
                        this->n++;
                break;

                case 4:
                    if(this->m>1&&obj.mas[this->n][this->m-1]==1&&obj.mas[this->n][this->m-2]==0)
                        m=m+2;
                    else if(this->m>0&&obj.mas[this->n][this->m-1]==0)
                        this->m--;
                break;
            }

            if(obj.mas[this->n][this->m]==0)
            {
                obj.mas[x][y]=0;
                obj.mas[this->n][this->m]=3;
                move =true;
            }
        }
    }
}
void Tp::Put(Mmap& obj)
{
    int x,y;
    id=4;
    bool create=false;
    while(!create)
    {
        x=rand()%obj.n;
        y=rand()%obj.m;

        if(obj.mas[x][y]==0)
        {
            this->n=x;
            this->m=y;
            obj.mas[x][y]=4;
            create =true;
        }
    }
}
void Tp::Move(Mmap& obj)
{
    if(this->n>=0||this->m>=0)
    {
        int x,y,k,l;
        x=this->n;
        y=this->m;
        bool move=false;
        while(!move)
        {
            k=rand()%4+1;
            l=rand()%3+1;

            switch (k)
            {
                case 1:
                    if(this->n>l&&obj.mas[this->n-l][this->m]==0)
                        this->n--;
                break;

                case 2:
                    if(this->m<obj.m-l&&obj.mas[this->n][this->m+l]==0)
                        this->m++;
                break;

                case 3:
                    if(this->n<obj.n-l&&obj.mas[this->n+l][this->m]==0)
                        this->n++;
                break;

                case 4:
                    if(this->m>l&&obj.mas[this->n][this->m-l]==0)
                        this->m--;
                break;
            }

            if(obj.mas[this->n][this->m]==0)
            {
                obj.mas[x][y]=0;
                obj.mas[this->n][this->m]=4;
                move =true;
            }
        }
    }
}
void Speed::Put(Mmap& obj)
{
    int x,y;
    id=5;
    bool create=false;
    while(!create)
    {
        x=rand()%obj.n;
        y=rand()%obj.m;

        if(obj.mas[x][y]==0)
        {
            this->n=x;
            this->m=y;
            obj.mas[x][y]=5;
            create =true;
        }
    }
}

void Speed::Move(Mmap& obj)
{
    if(this->n>=0||this->m>=0)
    {
        int x,y,k;
        x=this->n;
        y=this->m;
        bool move=false;
        while(!move)
        {
            k=rand()%4+1;

            switch (k)
            {
                case 1:
                    while(this->n>0&&obj.mas[this->n-1][this->m]==0)
                        this->n--;
                break;

                case 2:
                    while(this->m<obj.m&&obj.mas[this->n][this->m+1]==0)
                        this->m++;
                break;

                case 3:
                    while(this->n<obj.n&&obj.mas[this->n+1][this->m]==0)
                        this->n++;
                break;

                case 4:
                    while(this->m>0&&obj.mas[this->n][this->m-1]==0)
                        this->m--;
                break;
            }

            if(obj.mas[this->n][this->m]==0)
            {
                obj.mas[x][y]=0;
                obj.mas[this->n][this->m]=5;
                move =true;
            }
        }
    }
}

MGame::MGame(int count_h, int count_f,int count_t,int count_s)
{
    h=count_h, f=count_f,t=count_t, s=count_s;

    map=new Mmap(10,10);
    map->Generate();

    hero=new Hero[h];
    for(int i(0); i<h; i++)
        hero[i].Put(*map);

    fly=new Fly[f];
    for(int i(0); i<f; i++)
        fly[i].Put(*map);

    tp=new Tp[t];
    for(int i(0); i<t; i++)
        tp[i].Put(*map);

    speed=new Speed[s];
    for(int i(0); i<s; i++)
        speed[i].Put(*map);

    std::cout<<map;
}

void MGame::Check()
{
    for(int i(0); i<map->n ;++i)
        for(int j(0); j<map->m-1 ;++j)
            if(map->mas[i][j]!=0&&map->mas[i][j]!=1&&map->mas[i][j+1]!=0&&map->mas[i][j+1]!=1)
            {
                for(int b(0);b<h;b++)
                    if(map->mas[i][j]==hero[b].id)
                    {
                        map->mas[i][j]=0;
                        hero[b].n=-1;
                        hero[b].m=-1;
                    }else if(map->mas[i][j+1]==hero[b].id)
                    {
                        map->mas[i][j+1]=0;
                        hero[b].n=-1;
                        hero[b].m=-1;
                    }
                for(int b(0);b<f;b++)
                    if(map->mas[i][j]==fly[b].id)
                    {
                        map->mas[i][j]=0;
                        fly[b].n=-1;
                        fly[b].m=-1;
                    }else if(map->mas[i][j+1]==fly[b].id)
                    {
                        map->mas[i][j+1]=0;
                        fly[b].n=-1;
                        fly[b].m=-1;
                    }
                for(int b(0);b<t;b++)
                    if(map->mas[i][j]==tp[b].id)
                    {
                        map->mas[i][j]=0;
                        tp[b].n=-1;
                        tp[b].m=-1;
                    }else if(map->mas[i][j+1]==tp[b].id)
                    {
                        map->mas[i][j+1]=0;
                        tp[b].n=-1;
                        tp[b].m=-1;
                    }
                for(int b(0);b<s;b++)
                    if(map->mas[i][j]==speed[b].id)
                    {
                        map->mas[i][j]=0;
                        speed[b].n=-1;
                        speed[b].m=-1;
                    }else if(map->mas[i][j+1]==speed[b].id)
                    {
                        map->mas[i][j+1]=0;
                        speed[b].n=-1;
                        speed[b].m=-1;
                    }
            }
    for(int j(0);j<map->m;++j)
        for(int i(0);i<map->n-1;++i)
            if(map->mas[i][j]!=0&&map->mas[i][j]!=1&&map->mas[i+1][j]!=0&&map->mas[i+1][j]!=1)
            {
                for(int b(0);b<h;b++)
                    if(map->mas[i][j]==hero[b].id)
                    {
                        map->mas[i][j]=0;
                        hero[b].n=-1;
                        hero[b].m=-1;
                    }else if(map->mas[i+1][j]==hero[b].id)
                    {
                        map->mas[i+1][j]=0;
                        hero[b].n=-1;
                        hero[b].m=-1;
                    }
                for(int b(0);b<f;b++)
                    if(map->mas[i][j]==fly[b].id)
                    {
                        map->mas[i][j]=0;
                        fly[b].n=-1;
                        fly[b].m=-1;
                    }else if(map->mas[i+1][j]==fly[b].id)
                    {
                        map->mas[i+1][j]=0;
                        fly[b].n=-1;
                        fly[b].m=-1;
                    }
                for(int b(0);b<t;b++)
                    if(map->mas[i][j]==tp[b].id)
                    {
                        map->mas[i][j]=0;
                        tp[b].n=-1;
                        tp[b].m=-1;
                    }else if(map->mas[i+1][j]==tp[b].id)
                    {
                        map->mas[i+1][j]=0;
                        tp[b].n=-1;
                        tp[b].m=-1;
                    }
                for(int b(0);b<s;b++)
                    if(map->mas[i][j]==speed[b].id)
                    {
                        map->mas[i][j]=0;
                        speed[b].n=-1;
                        speed[b].m=-1;
                    }else if(map->mas[i+1][j]==speed[b].id)
                    {
                        map->mas[i][j+1]=0;
                        speed[b].n=-1;
                        speed[b].m=-1;
                    }
            }
}

void MGame::Turn()
{
    for(int i(0);i<h;i++)
        hero[i].Move(*map);
    for(int i(0);i<f;i++)
        fly[i].Move(*map);
    for(int i(0);i<t;i++)
        tp[i].Move(*map);
    for(int i(0);i<s;i++)
        speed[i].Move(*map);

    std::cout<<map;
    Check();
    std::cout<<map;
}

void MGame::SaveF()
{
    FILE *fout(NULL);
    fout=fopen("Save.txt","w");
    if (!fout)
		printf("Can not open file\n");
    for(int i=0;i<map->n;i++)
    {
		for(int j=0;j<map->m;j++)
			fprintf(fout,"%10d",map->mas[i][j]);
		fprintf(fout,"%c",'\n');
    }
	fclose(fout);
}

void MGame::LoadF()
{
    FILE *fin(NULL);
    fin=fopen("Save.txt","r");
    if (!fin)
		printf("Can not open file\n");
    for(int i=0;i<map->n;i++)
		for(int j=0;j<map->m;j++)
			fscanf(fin,"%d",&map->mas[i][j]);
    fclose(fin);

}

#endif
