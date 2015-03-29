var
  f,a:array[0..1000,0..1000] of longint;
  n,m,ans,i,j:longint;
begin
  read(n,m);
  for i:=1 to n do for j:=1 to m do read(a[i,j]);
  fillchar(f,sizeof(f),0);
  for i:=n downto 1 do
    for j:=m downto 1 do
      if a[i,j]<>0 then
        begin
          f[i,j]:=f[i+1,j];
          if f[i,j+1]<f[i,j] then f[i,j]:=f[i,j+1];
          if f[i+1,j+1]<f[i,j] then f[i,j]:=f[i+1,j+1];
          inc(f[i,j]);
        end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
      if f[i,j]>ans then ans:=f[i,j];
  writeln(ans);
end.
