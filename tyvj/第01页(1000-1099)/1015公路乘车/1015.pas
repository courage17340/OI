var
  a:array[0..10] of longint;
  f:array[0..1000] of longint;
  n,i,j:longint;
function min(a,b:longint):longint;
begin
  min:=a;
  if a>b then min:=b;
end;
begin
  for i:=1 to 10 do read(a[i]);
  readln(n);
  for i:=1 to n do
    f[i]:=maxlongint;
  for i:=1 to 10 do
    begin
      for j:=1 to n do
      if j>=i then
      f[j]:=min(f[j],f[j-i]+a[i]);
    end;
  writeln(f[n]);
end.