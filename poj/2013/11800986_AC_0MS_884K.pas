var
  a:array[1..15] of string;
  n,i,k:longint;
begin
  k:=0;
  while true do
    begin
      readln(n);
      if n=0 then break;
      inc(k);
      writeln('SET ',k);
      for i:=1 to n do readln(a[i]);
      for i:=1 to n do
        if i<=(n+1) shr 1 then writeln(a[i*2-1]) else writeln(a[n*2+2-2*i]);
    end;
end.