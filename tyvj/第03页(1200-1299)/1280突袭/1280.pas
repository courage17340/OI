var
  n,m,i,j:longint;
  a:array[1..100000] of ansistring;
  s:ansistring;
procedure sort(m,n:longint);
var
  i,j:longint;
  x,temp:ansistring;
begin
  x:=a[(m+n) div 2];
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
begin
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  s:='';
  if m=1 then
    for i:=1 to n do
      begin
        readln(j);
        if j<=length(a[i]) then s:=s+a[i][j];
      end;
  if m=2 then 
    for i:=n downto 1 do
      begin
        readln(j);
        if j<=length(a[i]) then s:=s+a[i][j];
      end;
  writeln(s);
end.