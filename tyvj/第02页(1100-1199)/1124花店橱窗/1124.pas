var
  a,f,path:array[0..110,0..110] of longint;
  n,m,ans,i,j,k:longint;
procedure p(i,j:longint);
begin
  if i>0 then
    begin
      p(i-1,path[i,j]);
      if i<>1 then write(' ');
      write(j);
    end;
end;
begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to n do
    for j:=1 to m do f[i,j]:=-maxlongint;
  for i:=1 to n do
    for j:=i to m-n+i do
      begin
        for k:=i-1 to j-1 do
          if f[i-1,k]>f[i,j] then begin f[i,j]:=f[i-1,k];path[i,j]:=k;end;
        f[i,j]:=f[i,j]+a[i,j];
      end;
  ans:=n;
  for i:=n+1 to m do
    if f[n,i]>f[n,ans] then ans:=i;
  writeln(f[n,ans]);
  p(n,ans);
  writeln;
end.