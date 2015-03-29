var
  a:array[0..100000] of longint;
  n,i,j,L,p:longint;
  ans,k:int64;
procedure sort(m,n:longint);
var
  i,j,x,temp:longint;
begin
  if n-m<=16 then
    begin
      for i:=m to n-1 do
        for j:=i+1 to n do
          if a[i]>a[j] then
            begin
              temp:=a[i];a[i]:=a[j];a[j]:=temp;
            end;
      exit;
    end;
  x:=a[(m+n) shr 1];
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
  readln(n,L);
  for i:=1 to n do read(a[i]);
  sort(1,n);
  k:=int64(int64(n)*int64(n-1) div int64(2));
  ans:=0;
  for i:=1 to n do if a[i]>L then break;
  if a[i]>L then dec(i);
  p:=i;j:=i;
  for i:=1 to p do
    begin
      while (a[i]+a[j]>L)and(j>1) do dec(j);
      if (a[i]+a[j]>L)and(j>0) then dec(j);
      if i>=j then break;
      if i<j then ans:=int64(ans+int64(j-i));
    end;
  writeln(ans/k:0:2);
  readln;readln;
end.