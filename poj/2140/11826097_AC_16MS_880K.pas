var
  n,ans,i:longint;
begin
  readln(n);
  ans:=0;
  for i:=1 to trunc(sqrt(n*2)) do
    if (odd(i) and (n mod i=0))or(not odd(i) and (n mod i=i shr 1)) then inc(ans);
  writeln(ans);
end.