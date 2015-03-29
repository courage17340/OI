var
  n,i,j,k,s,x:longint;
begin
  readln(n);
  for i:=1 to n do
    begin
      read(k);
      s:=1-k;
      for j:=1 to k do
        begin
          read(x);
          s:=s+x;
        end;
      writeln(s);
    end;
end.