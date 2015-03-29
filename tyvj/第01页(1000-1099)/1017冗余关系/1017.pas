var
  f:array[1..1000] of longint;
  n,m,i,j,k,ans:longint;
function top(x:longint):longint;
begin
  while x<>f[x] do x:=f[x];
  top:=x;
end;
procedure work(a,b:longint);
begin
  a:=top(a);
  b:=top(b);
  if a=b then inc(ans) else f[a]:=b;
end;
begin
  ans:=0;
  readln(m,n);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do
    begin
      readln(j,k);
      work(j,k);
    end;
  writeln(ans);
end.