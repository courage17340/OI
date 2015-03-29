var
  a,f:array[0..8000,0..1000] of longint;
  i,j,m,n,ans:longint;
function max(a,b:longint):longint;
begin
  max:=a;if a<b then max:=b;
end;
begin
  read(m,n);
  for i:=1 to n do for j:=1 to m do read(a[i,j]);
  fillchar(f,sizeof(f),128);
  for i:=1 to m do f[0,i]:=0;
  for i:=1 to n do
    for j:=1 to m do
      if a[i,j]<>-1 then
        begin
          f[i,j]:=max(f[i,j],f[i-1,j]);
          if j>1 then f[i,j]:=max(f[i,j],f[i-1,j-1]);
          if j<m then f[i,j]:=max(f[i,j],f[i-1,j+1]);
          if f[i,j]<0 then f[i,j]:=-maxlongint;
          inc(f[i,j],a[i,j]);
        end;
  ans:=-maxlongint;
  for i:=1 to m do if f[n,i]>ans then ans:=f[n,i];
  writeln(ans);
end.
