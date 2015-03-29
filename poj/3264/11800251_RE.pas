type rec=record L,r,max,min:longint;end;
var
  a:array[1..100000] of rec;
  b:array[1..50000] of longint;
  n,i,m,x,y:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
function min(a,b:longint):longint;
begin
  min:=a;
  if a>b then min:=b;
end;
procedure build(x,L,r:longint);
var
  m:longint;
begin
  a[x].L:=L;
  a[x].r:=r;
  if L=r then
    begin
      a[x].max:=b[L];
      a[x].min:=b[L];
      exit;
    end;
  m:=(L+r) shr 1;
  build(x*2,L,m);
  build(x*2+1,m+1,r);
  a[x].max:=max(a[x*2].max,a[x*2+1].max);
  a[x].min:=min(a[x*2].min,a[x*2+1].min);
end;
function f(k,x,y:longint):longint;
var
  m:longint;
begin
  if (a[k].L=x)and(a[k].r=y) then exit(a[k].max);
  m:=(a[k].L+a[k].r) shr 1;
  if y<=m then exit(f(k*2,x,y));
  if x>=m+1 then exit(f(k*2+1,x,y));
  exit(max(f(k*2,x,m),f(k*2+1,m+1,y)));
end;
function g(k,x,y:longint):longint;
var
  m:longint;
begin
  if (a[k].L=x)and(a[k].r=y) then exit(a[k].min);
  m:=(a[k].L+a[k].r) shr 1;
  if y<=m then exit(g(k*2,x,y));
  if x>=m+1 then exit(g(k*2+1,x,y));
  exit(min(g(k*2,x,m),g(k*2+1,m+1,y)));
end;
begin
  readln(n,m);
  for i:=1 to n do readln(b[i]);
  build(1,1,n);
  for i:=1 to m do
    begin
      readln(x,y);
      writeln(f(1,x,y)-g(1,x,y));
    end;
end.