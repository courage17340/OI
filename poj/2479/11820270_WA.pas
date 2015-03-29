var
  a:array[1..50000] of longint;
  ans1,ans2,i,j,n,k,s,t:longint;
begin
  readln(k);
  for s:=1 to k do
    begin
      readln(n);
      for i:=1 to n do read(a[i]);
      ans1:=a[1];
      ans2:=a[2];
      if ans1<ans2 then
        begin
          t:=ans1;ans1:=ans2;ans2:=t;
        end;
      t:=a[1];
      if t<0 then t:=0;
      for i:=2 to n do
        if t+a[i]>=0 then
          begin
            t:=t+a[i];
            if t>=ans1 then
              begin
                ans1:=t;
                ans2:=ans1;
              end else
              ans2:=t;
          end else t:=0;
      writeln(ans1+ans2);
    end;
end.