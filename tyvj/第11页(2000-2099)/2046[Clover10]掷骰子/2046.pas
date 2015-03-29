var
  a:array[1..50010] of longint;
  n,i,j,k:longint;
  ans:real;
procedure sort(m,n:longint);
var
  i,j,x,temp:longint;
begin
  if n-m<=16 then
    begin
      for i:=m to n-1 do
        for j:=i+1 to n do
          if a[i]<a[j] then
            begin
              temp:=a[i];a[i]:=a[j];a[j]:=temp;
            end;
      exit;
    end;
  x:=a[(m+n) shr 1];
  i:=m;
  j:=n;
  repeat
    while a[i]>x do i:=i+1;
    while a[j]<x do j:=j-1;
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
  readln(n);
  for i:=1 to n do read(a[i]);readln;
  sort(1,n);
  j:=0;ans:=0;
  for i:=1 to n do
    begin
      ans:=ans+(j+j+a[i]+1)/2;
      j:=j+a[i];
    end;
  writeln(ans:0:3);
  readln;
end.