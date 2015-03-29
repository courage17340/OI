var
  a:array[1..50] of longint;
  n,i,j,s,k,ans:longint;
begin
  k:=0;
  while true do
    begin
      readln(n);
      if n=0 then break;
      s:=0;
      inc(k);
      writeln('Set #',k);
      write('The minimum number of moves is ');
      for i:=1 to n do
        begin
          read(a[i]);
          s:=s+a[i];
        end;
      s:=s div n;
      ans:=0;
      for i:=1 to n-1 do
        if a[i]<>s then
          begin
            a[i+1]:=a[i+1]+a[i]-s;
            a[i]:=s;
            inc(ans);
          end;
      writeln(ans,'.');
      writeln;
    end;
end.