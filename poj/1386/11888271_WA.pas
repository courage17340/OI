var
  t,n,i,j,k:longint;
  s:ansistring;
  f:array[1..26] of longint;
begin
  readln(t);
  for k:=1 to t do
    begin
      readln(n);
      fillchar(f,sizeof(f),0);
      for i:=1 to n do
        begin
          readln(s);
          inc(f[ord(s[1])-96]);
          dec(f[ord(s[length(s)])-96]);
        end;
      j:=0;
      for i:=1 to 26 do inc(j,abs(f[i]));
      if j<=2 then writeln('Ordering is possible.') else writeln('The door cannot be opened.');
    end;
end.