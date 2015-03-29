var
  a,b:array[0..200] of int64;
  n,i,j,k:longint;
  ans:int64;
begin
  readln(k,n);
  a[0]:=1;
  for i:=1 to trunc(ln(1e11)/ln(k)) do a[i]:=a[i-1]*int64(k);
  i:=-1;
  while n>0 do
    begin
      inc(i);
      b[i]:=n mod 2;
      n:=n shr 1;
    end;
  j:=i;
  ans:=0;
  for i:=0 to j do
    ans:=ans+a[i]*b[i];
  writeln(ans mod int64(2147483648));
end.