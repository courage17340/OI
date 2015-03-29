type rec=record x,y:longint;end;
var
  a:array[0..200000] of rec;
  f:array[0..100000] of longint;
  i,m,n,c,t,max:longint;
procedure sort(m,n:longint);
var
  i,j,x:longint;
  temp:rec;
begin
  x:=a[(m+n) div 2].x;
  i:=m;
  j:=n;
  repeat
    while a[i].x<x do i:=i+1;
    while a[j].x>x do j:=j-1;
    if i<=j then
      begin
        temp:=a[i];
        a[i]:=a[j];
        a[j]:=temp;
        i:=i+1;
        j:=j-1;
      end;
    until i>j;
  if m<j then sort(m,j);
  if i<n then sort(i,n);
end;
function find(x,y,p:longint):longint;
var mid:longint;
begin
  mid:=(x+y) div 2;
  if a[mid].x=p then begin while a[mid-1].x=p do dec(mid);exit(mid);end;
  if a[mid].x>p then exit(find(x,mid-1,p));
  exit(find(mid+1,y,p));
end;
procedure work(p:longint);
var i,j:longint;
begin
  i:=find(1,2*m,p);
  while a[i].x=p do
    begin
      if f[a[i].y]>f[p]+1 then
        begin f[a[i].y]:=f[p]+1;work(a[i].y);end;
      inc(i);
    end;
end;
begin
  read(n,m,c,t);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
    begin
      read(a[i*2].x,a[i*2].y);
      if a[i*2].x<a[i*2].y then begin max:=a[i*2].x;a[i*2].x:=a[i*2].y;a[i*2].y:=max;end;
      a[i*2-1].x:=a[i*2].y;a[i*2-1].y:=a[i*2].x;
    end;
  sort(1,m*2);
  fillchar(f,sizeof(f),127);
  f[c]:=0;max:=0;
  work(c);
  for i:=1 to n do if max<f[i] then max:=f[i];
  writeln(max+t+1);
end.