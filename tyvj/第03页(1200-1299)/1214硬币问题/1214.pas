var
  s,n,i,j,max:longint;
  f,a:array[0..10000]of longint;
begin
  read(n,s);
  for i:=1 to n do read(a[i]);
  for i:=1 to s do f[i]:=-maxlongint;
  f[0]:=0;
  for i:=1 to s do
    for j:=1 to n do
      if i>=a[j] then
        if f[i-a[j]]+1>f[i] then
          f[i]:=f[i-a[j]]+1;
  max:=f[s];
  fillchar(f,sizeof(f),127);
  f[0]:=0;
  for i:=1 to s do
    for j:=1 to n do
      if i>=a[j] then
        if f[i-a[j]]+1<f[i] then
          f[i]:=f[i-a[j]]+1;
  writeln(f[s]);
  writeln(max);
end.
