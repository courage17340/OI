type
 rec=record x,y,v:longint;end;
var
  a:array[0..160,0..160] of char;
  f:array[0..160,0..160] of longint;
  d:array[0..30000] of rec;
  n,m,i,j,x1,x2,y1,y2:longint;
function next(x:longint):longint;
begin
  next:=x+1;if next=30001 then next:=0;
end;
begin
  readln(m,n);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(a[i,j]);
          if a[i,j]='K' then begin x1:=i;y1:=j;end;
          if a[i,j]='H' then begin x2:=i;y2:=j;end;
        end;
      readln;
    end;
  fillchar(f,sizeof(f),1);
  f[x1,y1]:=0;
  i:=0;j:=0;
  d[0].x:=x1;d[0].y:=y1;d[0].v:=0;
  while next(j)<>i do
    begin
      if (d[i].x-2>0)and(d[i].y-1>0) then if (f[d[i].x-2,d[i].y-1]>d[i].v+1)and(a[d[i].x-2,d[i].y-1]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x-2;d[j].y:=d[i].y-1;d[j].v:=d[i].v+1;f[d[i].x-2,d[i].y-1]:=d[j].v;end;
      if (d[i].x-2>0)and(d[i].y+1<=m) then if (f[d[i].x-2,d[i].y+1]>d[i].v+1)and(a[d[i].x-2,d[i].y+1]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x-2;d[j].y:=d[i].y+1;d[j].v:=d[i].v+1;f[d[i].x-2,d[i].y+1]:=d[j].v;end;
      if (d[i].x-1>0)and(d[i].y-2>0) then if (f[d[i].x-1,d[i].y-2]>d[i].v+1)and(a[d[i].x-1,d[i].y-2]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x-1;d[j].y:=d[i].y-2;d[j].v:=d[i].v+1;f[d[i].x-1,d[i].y-2]:=d[j].v;end;
      if (d[i].x-1>0)and(d[i].y+2<=m) then if (f[d[i].x-1,d[i].y+2]>d[i].v+1)and(a[d[i].x-1,d[i].y+2]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x-1;d[j].y:=d[i].y+2;d[j].v:=d[i].v+1;f[d[i].x-1,d[i].y+2]:=d[j].v;end;
      if (d[i].x+1<=n)and(d[i].y-2>0) then if (f[d[i].x+1,d[i].y-2]>d[i].v+1)and(a[d[i].x+1,d[i].y-2]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x+1;d[j].y:=d[i].y-2;d[j].v:=d[i].v+1;f[d[i].x+1,d[i].y-2]:=d[j].v;end;
      if (d[i].x+1<=n)and(d[i].y+2<=m) then if (f[d[i].x+1,d[i].y+2]>d[i].v+1)and(a[d[i].x+1,d[i].y+2]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x+1;d[j].y:=d[i].y+2;d[j].v:=d[i].v+1;f[d[i].x+1,d[i].y+2]:=d[j].v;end;
      if (d[i].x+2<=n)and(d[i].y-1>0) then if (f[d[i].x+2,d[i].y-1]>d[i].v+1)and(a[d[i].x+2,d[i].y-1]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x+2;d[j].y:=d[i].y-1;d[j].v:=d[i].v+1;f[d[i].x+2,d[i].y-1]:=d[j].v;end;
      if (d[i].x+2<=n)and(d[i].y+1<=m) then if (f[d[i].x+2,d[i].y+1]>d[i].v+1)and(a[d[i].x+2,d[i].y+1]<>'*') then
        begin j:=next(j);d[j].x:=d[i].x+2;d[j].y:=d[i].y+1;d[j].v:=d[i].v+1;f[d[i].x+2,d[i].y+1]:=d[j].v;end;
      i:=next(i);
    end;
  writeln(f[x2,y2]);
end.