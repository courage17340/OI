var
  n,a:longint;
  ans:int64;
begin
  while not eof do
    begin
      readln(n);
      if n=0 then break;
      a:=0;
      while a*(a+1) shr 1<=n do inc(a);
      dec(a);
      ans:=int64(a)*int64(a+1)*int64(2*a+1) div int64(6)+int64(n-a*(a+1) shr 1)*int64(a+1);
      writeln(n,' ',ans);
    end;
end.