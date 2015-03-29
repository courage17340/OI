var
  a,f:array[0..1000] of longint;
  n,i,j:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  a[0]:=-maxlongint;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=0 to i-1 do
      if a[i]>a[j] then f[i]:=max(f[i],f[j]+1);
  for i:=1 to n do if f[0]<f[i] then f[0]:=f[i];
  writeln(f[0]);
end.