var
  n,i,a,b:longint;
function zhi(x:longint):boolean;
var i:longint;
begin
  if x<=3 then exit(true);
  zhi:=true;
  for i:=2 to trunc(sqrt(x)) do
    if x mod i=0 then exit(false);
end;
function pan(x:longint):longint;
begin
  if (x=1) or zhi(x) then exit(1);
  if x mod 2=0 then exit(2);
  if zhi(x-2) then exit(2);
  exit(3);
end;
begin
  read(n);
  for i:=1 to n do
    begin
      read(a,b);
      if (a>b)and(pan(a)<=pan(b)) or (pan(a)<pan(b)) then writeln('YES') else writeln('NO');
    end;
end.