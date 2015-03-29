var
  a:array[0..1000] of longint;
  f:array[0..1000,0..1000] of longint;
  n,i,j,ans:longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=0 to i-1 do
      begin
        if (a[i]=i-j) then f[i,j]:=f[i-1,j]+1 else f[i,j]:=f[i-1,j];
        if f[i-1,j-1]>f[i,j] then f[i,j]:=f[i-1,j-1];
      end;
  ans:=0;
  for i:=0 to i do if ans<f[n,i] then ans:=f[n,i];
  writeln(ans);
end.
