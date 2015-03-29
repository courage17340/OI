var
  f:array['A'..'Z'] of longint;
  a:array[1..10000] of longint;
  n,i:longint;
  s:string;
  t,ans:int64;
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

function value(s:string):longint;
var
  i:longint;
begin
  value:=0;
  for i:=1 to length(s) do value:=value+f[upcase(s[i])];
end;

begin
  readln(t,n);
  for i:=1 to 26 do read(f[chr(i+ord('A')-1)]);
  readln;
  for i:=1 to n do
    begin
      readln(s);
      a[i]:=value(s);
    end;
  sort(1,n);
  ans:=0;
  for i:=1 to n do
    begin
      ans:=ans+int64(a[i]);
      if ans>t then begin writeln('No');writeln(i-1);readln;halt;end;
    end;
  writeln('Yes');
  writeln(t-ans);
  readln;
end.