var
  a:array[1..110] of longint;
  n,i,j,sum,ans:longint;
begin
  readln(n);
  sum:=0;
  for i:=1 to n do begin read(a[i]);sum:=sum+a[i];end;readln;
  sum:=sum div n;
  ans:=0;
  for i:=1 to n-1 do
    if a[i]<>sum then
      begin
        a[i+1]:=a[i+1]+a[i]-sum;
        a[i]:=sum;
        inc(ans);
      end;
  writeln(ans);
end.