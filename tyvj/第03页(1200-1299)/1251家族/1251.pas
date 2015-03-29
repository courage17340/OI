var
  f:array[1..5000] of longint;
  n,m,p,i,j,k:longint;
function top(x:longint):longint;
begin
  while x<>f[x] do x:=f[x];
  top:=x;
end;
procedure work(a,b:longint);
begin
  a:=top(a);
  b:=top(b);
  if a<>b then f[a]:=b;
end;
function pan(a,b:longint):string;
begin
  if top(a)=top(b) then exit('Yes');
  exit('No');
end;
begin
  readln(n,m,p);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do
    begin
      readln(j,k);
      work(j,k);
    end;
  for i:=1 to p do
    begin
      readln(j,k);
      writeln(pan(j,k));
    end;
end.