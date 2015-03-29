var
  a,b:array[1..9,1..9] of longint;
  c:array[1..81,1..2] of longint;
  x,y,z:array[1..9] of string;
  i,j,k,s,w,n,q:longint;
  st:string;
  flag:boolean;
function f(x,y:longint):longint;
begin
  f:=((x-1) div 3)*3+(y-1) div 3+1;
end;
procedure print;
var
  i,j:longint;
begin
  for i:=1 to 9 do
    begin
      for j:=1 to 9 do write(a[i,j]);
      writeln;
    end;
  flag:=true;
end;
procedure test;
var
  i:longint;
begin
  for i:=1 to 9 do if x[i]<>'111111111' then exit;
  for i:=1 to 9 do if y[i]<>'111111111' then exit;
  for i:=1 to 9 do if z[i]<>'111111111' then exit;
  print;
end;
procedure work(p,q,k,h:longint);
var
  i:longint;
begin
  if h+s>81 then exit;
  if flag then exit;
  if x[p][k]='1' then exit;
  if y[q][k]='1' then exit;
  if z[b[p,q]][k]='1' then exit;
  a[p,q]:=k;
  x[p][k]:='1';
  y[q][k]:='1';
  z[b[p,q]][k]:='1';
  if h+s=81 then begin test;exit;end;
  for i:=1 to 9 do work(c[h+1][1],c[h+1][2],i,h+1);
  a[p,q]:=0;
  x[p][k]:='0';
  y[q][k]:='0';
  z[b[p,q]][k]:='0';
end;
begin
 readln(n);
 for q:=1 to n do
 begin
  flag:=false;
  for i:=1 to 9 do
    for j:=1 to 9 do b[i,j]:=f(i,j);
  for i:=1 to 9 do
    begin
      x[i]:='000000000';
      y[i]:=x[i];
      z[i]:=y[i];
      readln(st);while length(st)<9 do readln(st);
      for j:=1 to 9 do a[i,j]:=ord(st[j])-48;
    end;
  s:=0;
  w:=0;
  for i:=1 to 9 do
    for j:=1 to 9 do if a[i,j]<>0 then
      begin
        x[i][a[i,j]]:='1';
        y[j][a[i,j]]:='1';
        z[b[i,j]][a[i,j]]:='1';
        inc(s);
      end
      else begin inc(w);c[w][1]:=i;c[w][2]:=j;end;
  for k:=1 to 9 do work(c[1][1],c[1][2],k,1);
 end;
end. 