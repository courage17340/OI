var
  n,i,x:longint;
function min(a,b:int64):int64;
begin
  min:=a;
  if a>b then min:=b;
end;
function sum(x:int64):int64;
var
  i,j,k,y:int64;
begin
  sum:=0;
  k:=1;//1,11,111,...
  j:=1;//1,2,3,...
  y:=1;//1,10,100,...
  while x>=y do
    begin
      sum:=sum+int64(((y+min(x,int64(y*10-1)))*j+j*int64(2)-int64(k*2))*int64(min(x,y*10-1)-y+1) shr int64(1));
      k:=k*10+1;
      inc(j);
      y:=y*10;
    end;
end;
function f(x:longint):longint;
var
  i,j,k:longint;
begin
  k:=trunc(ln(x)/ln(10))+1;
  j:=1;
  for i:=2 to k do j:=j*10+1;
  exit(x*k+k-j);
end;
function search(x:longint):longint;
var
  i,j,k,L,r,m:longint;
  p:int64;
  s:ansistring;
  t:string;
begin
  L:=1;
  r:=32000;
  m:=(L+r) shr 1;
  while L+1<r do
    begin
      p:=sum(m);
      if p=x then break;
      if p<x then L:=m;
      if p>x then r:=m;
      m:=(L+r) shr 1;
    end;
  x:=x-sum(m);
  if x=0 then exit(m mod 10);
  s:='';
  for i:=1 to m+1 do
    begin
      str(i,t);
      s:=s+t;
    end;
  exit(ord(s[x])-48);
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(x);
      writeln(search(x));
    end;
end.