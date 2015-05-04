Given(/^a file ([a-zA-Z0-9\-\.]+)$/) do |filename|
  expect(File.exist?(filename)).to eq(true)
end

Then(/^the output file ([a-zA-Z0-9\-\.]+) is there$/) do |filename|
  expect(File.exist?(filename)).to eq(true)
end

Given(/^a file sample\.in and sample\.expected$/) do
  expect(File.exist?("sample.in")).to eq(true)
  expect(File.exist?("sample.expected")).to eq(true)
end

When(/^I execute program with ([a-zA-Z0-9\-]+)$/) do |filename|
  FileUtils.mkdir_p("build")
  Dir.chdir("build")
  `bin/exec < ../#{filename}.in > ../#{filename}.out`
  Dir.chdir("..")
end

When(/^I execute ruby with ([a-zA-Z0-9\-]+)$/) do |filename|
  `ruby main.rb < #{filename}.in > #{filename}.out`
end

Then(/^check the ([a-zA-Z0-9\-\.]+) with ([a-zA-Z0-9\-\.]+)$/) do |filename1, filename2|
  f1 = File.open(filename1)
  f2 = File.open(filename2)

  file1lines = f1.readlines
  file2lines = f2.readlines

  expect(file1lines.count).to eq(file2lines.count)

  for i in 0..file1lines.count do
    expect(file1lines[i]).to eq(file2lines[i])
  end
end
