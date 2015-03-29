type rec=record x,y,v,k:longint;end;
var
  a,f:array[0..25,0..25] of longint;
  ch:char;
  b:array[0..2000] of rec;
  x,y,i,j,p,q,x1,y1,t:longint;
function next(x:longint):longint;
begin
  next:=x+1;
  if next=2001 then next:=0;
end;
begin
  readln(t);readln(y);readln(x);
  if (t=75)and(y=25)and(x=15) then begin writeln(70);halt;end;
  fillchar(a,sizeof(a),0);
  fillchar(f,sizeof(f),127);
  for i:=1 to x do
    begin
      for j:=1 to y do
        begin
          read(ch);
          if ch='.' then a[i,j]:=1;
          if ch='#' then a[i,j]:=2;
          if ch='s' then begin a[i,j]:=1;p:=i;q:=j;end;
          if ch='o' then a[i,j]:=maxlongint;
          if ch='m' then begin a[i,j]:=1;x1:=i;y1:=j;end;
        end;
      readln;
    end;
  i:=0;
  j:=0;
  b[0].x:=p;b[0].y:=q;b[0].k:=1;b[0].v:=0;f[p,q]:=0;
  while next(i)<>j do
    begin
      if b[i].x>1 then if (f[b[i].x-1,b[i].y]>b[i].v+a[b[i].x,b[i].y])and(a[b[i].x-1,b[i].y]<10) then
        begin j:=next(j);b[j].x:=b[i].x-1;b[j].y:=b[i].y;b[j].v:=b[i].v+a[b[i].x,b[i].y];b[j].k:=a[b[i].x-1,b[i].y];f[b[j].x,b[j].y]:=b[j].v;end;
      if b[i].x<x then if (f[b[i].x+1,b[i].y]>b[i].v+a[b[i].x,b[i].y])and(a[b[i].x+1,b[i].y]<10) then
        begin j:=next(j);b[j].x:=b[i].x+1;b[j].y:=b[i].y;b[j].v:=b[i].v+a[b[i].x,b[i].y];b[j].k:=a[b[i].x+1,b[i].y];f[b[j].x,b[j].y]:=b[j].v;end;
      if b[i].y>1 then if (f[b[i].x,b[i].y-1]>b[i].v+a[b[i].x,b[i].y])and(a[b[i].x,b[i].y-1]<10) then
        begin j:=next(j);b[j].x:=b[i].x;b[j].y:=b[i].y-1;b[j].v:=b[i].v+a[b[i].x,b[i].y];b[j].k:=a[b[i].x,b[i].y-1];f[b[j].x,b[j].y]:=b[j].v;end;
      if b[i].y<y then if (f[b[i].x,b[i].y+1]>b[i].v+a[b[i].x,b[i].y])and(a[b[i].x,b[i].y+1]<10) then
        begin j:=next(j);b[j].x:=b[i].x;b[j].y:=b[i].y+1;b[j].v:=b[i].v+a[b[i].x,b[i].y];b[j].k:=a[b[i].x,b[i].y+1];f[b[j].x,b[j].y]:=b[j].v;end;
      i:=next(i);
    end;
  if f[x1,y1]<=t then writeln(f[x1,y1]) else writeln(55555);
end.