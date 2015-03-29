var
  a,b:array[0..20] of longint;
  n,i,k,ans:longint;
function prime(x:longint):boolean;
var
  i:longint;
begin
  if x=1 then exit(false);
  for i:=2 to trunc(sqrt(x)) do
    if x mod i=0 then exit(false);
  exit(true);
end;

procedure find(p,q:longint);
var
  i,j:longint;
begin
  if q=k then
    begin
      j:=0;
      for i:=1 to k do inc(j,a[b[i]]);
      if prime(j) then inc(ans);
      exit;
    end;
  for i:=p+1 to q+n-k+1 do
    begin
      b[q+1]:=i;
      find(i,q+1);
    end;
end;

begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  ans:=0;
  find(0,0);
  writeln(ans);
end.