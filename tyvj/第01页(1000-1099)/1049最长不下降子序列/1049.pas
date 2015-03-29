var
  a,f:array[0..5000] of longint;
  i,j,n:longint;
function max(a,b:longint):longint;
begin
  max:=a;
  if a<b then max:=b;
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do f[i]:=1;
  for i:=2 to n do
    for j:=1 to i-1 do
      if a[i]>=a[j] then f[i]:=max(f[i],f[j]+1);
  j:=0;
  for i:=1 to n do if j<f[i] then j:=f[i];
  writeln(j);
end.