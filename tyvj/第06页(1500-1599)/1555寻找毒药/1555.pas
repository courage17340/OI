var
  n,k:longint;
  s:double;
begin
  readln(n,k);
  s:=ln(n)/ln(k+1);
  if s<>trunc(s) then s:=trunc(s)+1;
  writeln(s:0:0);
  readln;
end.