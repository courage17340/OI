var
  k,p,n,ans,i,j:longint;
begin
  readln(k);
  for j:=1 to k do
    begin
      readln(p,n);
      ans:=0;
      for i:=1 to trunc(sqrt(n*2)) do
        if (odd(i) and (n mod i=0))or(not odd(i) and (n mod i=i shr 1)) then inc(ans);
      writeln(p,' ',ans-1);
    end;
end.