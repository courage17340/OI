var
  f:array[0..4000] of longint;
  n,m,i,x,y:longint;
  zhi,fei:longint;
function top(x:longint):longint;
begin
  top:=x;
  while f[top]<>top do top:=f[top];
  f[x]:=top;
end;
function iszhi(x:longint):boolean;
var i:longint;
begin
  if x=1 then exit(false);
  for i:=2 to trunc(sqrt(x)) do if x mod i=0 then exit(false);
  exit(true);
end;
begin
  read(n,m);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do
    begin
      read(x,y);
      if top(x)<>top(y) then f[top(x)]:=top(y);
    end;
  read(x);zhi:=0;fei:=0;
  for i:=1 to n do if top(x)=top(i) then
    if iszhi(i) then inc(zhi) else inc(fei);
  if zhi<fei then writeln(zhi) else writeln(fei);
end.
