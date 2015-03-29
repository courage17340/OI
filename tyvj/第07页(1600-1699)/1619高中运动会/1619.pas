var
  n,a,i,ans:longint;
function gcd(a,b:longint):longint;
begin
  if b=0 then exit(a);
  exit(gcd(b,a mod b));
end;
begin
  readln(n);
  read(ans);
  for i:=2 to n do
    begin
      read(a);
      ans:=gcd(ans,a);
    end;
  writeln(ans);
end.