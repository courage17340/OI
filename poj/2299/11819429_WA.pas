var
  a,b,c:array[1..500000] of longint;
  n,i,j,ans:longint;
procedure merge(x,y:longint);
var
  m,i,j,p,q,k,s:longint;
begin
  if x=y then exit;
  m:=(x+y) shr 1;
  merge(x,m);
  merge(m+1,y);
  for i:=x to m do b[i-x+1]:=a[i];
  for i:=m+1 to y do c[i-m]:=a[i];
  i:=1;
  j:=1;
  p:=m-x+1;
  q:=y-m;
  k:=x-1;
  while (i<=p)and(j<=q) do
    begin
      if b[i]<=c[j] then
        begin
          inc(k);
          a[k]:=b[i];
          inc(i);
        end else
        begin
          inc(k);
          a[k]:=c[j];
          inc(j);
          inc(ans,p-i+1);
        end;
    end;
  if i>p then
    for s:=j to q do
      begin
        inc(k);
        a[k]:=c[s];
      end;
  if j>q then
    for s:=i to p do
      begin
        inc(k);
        a[k]:=b[s];
      end;
end;
begin
  while true do
    begin
      readln(n);
      if n=0 then break;
      for i:=1 to n do readln(a[i]);
      ans:=0;
      merge(1,n);
      writeln(ans);
    end;
end.