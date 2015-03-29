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
      for i:=1 to n do
        begin
          a[i]:=a[i]-s;
          if a[i]>0 then ans:=ans+a[i];
        end;
      writeln(ans,'.');
      writeln;
    end;
end.