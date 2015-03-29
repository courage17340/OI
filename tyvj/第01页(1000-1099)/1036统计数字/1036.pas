var
  a:array[0..200000] of longint;
  n,m:longint;
procedure init;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
end;
procedure sort(m,n:longint);
var
  i,j,x,temp:longint;
begin
  x:=a[m];
  i:=m;
  j:=n;
  repeat
    while a[i]<x do i:=i+1;
    while a[j]>x do j:=j-1;
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
procedure work;
var
  x,i,count:longint;
begin
  sort(1,n);
  m:=1;
  x:=a[1];
  count:=1;
  for i:=2 to n do
    if a[i]=x
      then
        inc(count)
      else
        begin
          writeln(x,' ',count);
          count:=1;
          x:=a[i];
        end;
  writeln(x,' ',count);
end;
begin
  init;
  work;
end.