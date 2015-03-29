var
 m,n,i,j,x1,x2,y1,y2:longint;
 a:array[1..50,1..50]of longint;
 f:array[0..50,0..50,0..50,0..50]of longint;
function max(a,b,c,d:longint):longint;
begin
 max:=a;
 if b>max then max:=b;
 if c>max then max:=c;
 if d>max then max:=d;
end;
begin
 read(m,n);
 fillchar(f,sizeof(f),0);
 for i:=1 to m do
   for j:=1 to n do
     read(a[i,j]);
 a[1,1]:=0;a[m,n]:=0;
 for x1:=1 to m do
    for y1:=1 to n do
      for x2:=x1+1 to m do
        begin
          y2:=x1+y1-x2;
          if (y2>=1)and(y2<=n) then
          f[x1,y1,x2,y2]:=max(f[x1-1,y1,x2-1,y2],f[x1-1,y1,x2,y2-1],f[x1,y1-1,x2-1,y2],f[x1,y1-1,x2,y2-1])+a[x1,y1]+a[x2,y2];
        end;
 f[m,n,m,n]:=max(f[m-1,n,m-1,n],f[m-1,n,m,n-1],f[m,n-1,m-1,n],f[m,n-1,m,n-1])+a[m,n];
 writeln(f[m,n,m,n]);
end.